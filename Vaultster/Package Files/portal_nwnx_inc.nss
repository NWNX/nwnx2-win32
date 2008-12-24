// Name     : Portal include file
// Purpose  : Misc code for portalling between servers with NWNX Vaultster
// Authors  : Ingmar Stieger
// Modified : December 14, 2003
// January 13, 2005, By Mistcaller to add crafting xp transfer.
// May 7, 2005 Adapted code for updated Vaultster version
// Dec 13, 2005 By Themicles - Made a fix to WaitForPortalReady
//             to try a modified filename search if the first failed.
//             this fixes portalling for several players who are victims
//             of NWN's inconsistent naming of BIC files.
// Modified : Dec 16, 2005 - Changed the error message from the above fix.
//          : and added a line to delete the retry variable when successfully
//          : portalling
// Modified : Themicles - Added file name search retries on fail, limited by
//          : iMaxNameRetries.
// Modified : Jan 5, 2006 - File made standard. All "SEND" entries changed to
//          : "VAULTSTER" and crafting XP transfer now uses a switch to determine
//          : whether it should run. Eliminated dependance on portal_include.nss
//          : and cut database access down to 1 call per full portalling attempt.
// Modified : Feb 23, 2006 by Zebranky - Changed values of constants both here and
//          : in the DLL in an attempt to fix an elusive bug with status reporting.
//          : You MUST have the associated version of nwnx_vaultster.dll for this
//          : to work!
// Modified : Sept 30, 2006 by Themicles - Updated filename function to fix a bug
//          : with long file names. Tested and working as intended.
// Modified : Oct 28, 2006 by Themicles - Updated the PortalPlayerNWNX and WaitForPortalReady
//          : functions to allow for an optional location tracking setting. If you do not wish
//          : to use cross-world location tracking, you do not need to do *anything*. It defaults
//          : to 0 so you wont have to update any of your scripts to add in a new var to your
//          : calls to PortalPlayerNWNX.
// Modified : Dec 30, 2006 by Zebranky - Removed the player name retry code, as a fix
//          : to Vaultster itself should make this unnecessary. Also reverted 9/30/06,
//          : added a check for blank portaldata to avoid looping "Too many clients
//          : already" error, and added multiport functionality. (Released 1/14/07.)
// Modified : Dec 24, 2008 by Zebranky - Removed CoPaP specific features for public
//          : NWNX release.

#include "aps_include"

//void main(){}

// Error codes returned by VaultSter
const int VAULTSTER_OK = 0;
const int VAULTSTER_FAILED = -1;
const int VAULTSTER_SERVERBUSY = -2;
const int VAULTSTER_NOPLAYER = -3;
const int VAULTSTER_INTERNALERROR = -4;

// Status messages
const int VAULTSTER_STATUS_BUSY = 0;
const int VAULTSTER_STATUS_OK   = 2;
const int VAULTSTER_STATUS_ERROR= 3;

// Constants

const int iMaxTries = 30;
const int IDLE = 0;
const int BUSY = 1;

//**********************//
// Function Definitions //
//**********************//

//Used to check the current status of oPC's portalling attempt.
int PortalStatus (object oPC);

//Waits for VAULTSTER_STATUS_OK, then logs the player into the target server.
//This also handles retrying on VAULTSTER_STATUS_BUSY, and VAULTSTER_STATUS_ERROR.
void WaitForPortalReady(object oPlayer, object oPortal, struct ServerData portaldata, string sWaypoint);

//This takes the character's name and converts it into the character's filename.
string ConvertToFilename(string sPlayerName);

//This function sets the job that tells Vaultster to send the BIC.
void PortalPlayerNWNX(object oPlayer, object oPortal, string sServer, string sWaypoint);

//****************//
// Implementation //
//****************//
struct ServerData
{
    string servername;
    string address;
    string playerpassword;
    string dmpassword;
    string vaultport;
};

struct ServerData LoadServerData(string sServerName)
{
    struct ServerData portaldata;

    SQLExecDirect("SELECT name, address, playerpassword, dmpassword, vaultport FROM servers WHERE name='" + sServerName + "'");

    if(SQLFetch() == SQL_SUCCESS)
    {
        portaldata.servername = SQLGetData(1);
        portaldata.address = SQLGetData(2);
        portaldata.playerpassword = SQLGetData(3);
        portaldata.dmpassword = SQLGetData(4);
        portaldata.vaultport = SQLGetData(5);
    }

    return portaldata;
}

int PortalStatus (object oPC)
{
    // get the portal id from the player
    int id = GetLocalInt(oPC, "VAULTSTER_ID");
    if (id == 0)
        return VAULTSTER_STATUS_ERROR;

    // get the status from Vaultster
    object oModule = GetModule();
    SetLocalString(oModule, "NWNX!VAULTSTER!STATUS", IntToString(id-1));
    return StringToInt(GetLocalString(oModule, "NWNX!VAULTSTER!STATUS"));
}

void ClearPortalAttemptVar(object oPlayer)
{
    DeleteLocalInt(oPlayer, "portal_attempting");
}

string ConvertToFilename(string sPlayerName)
{
    string sRes;
    string sChar;
    int i, j;

    int iLen = GetStringLength(sPlayerName);
    if(iLen > 16)
      iLen = 16;

    for (i = 0; i < iLen; i++)
    {
        sChar = GetSubString(sPlayerName, i + j, 1);
        if ((sChar != " ") && (sChar != "."))
            sRes += sChar;
        else
        {
            i--;
            j++;
        }
    }
    return sRes;
}

void WaitForPortalReady(object oPlayer, object oPortal, struct ServerData portaldata, string sWaypoint)
{
    int iNWNXStatus = PortalStatus(oPlayer);

    if (iNWNXStatus == VAULTSTER_STATUS_OK)
    {
        //File successfully sent. Remove variables and log the player into the target server.
        DeleteLocalInt(oPlayer, "portal_tries");
        DeleteLocalInt(oPlayer, "VAULTSTER_ID");

        ActivatePortal(oPlayer, portaldata.address, portaldata.playerpassword, sWaypoint, TRUE);
    }
    else if (iNWNXStatus == VAULTSTER_STATUS_BUSY)
    {
        //Still busy sending file. Wait and try again later. Limited by constant iMaxTries.
        int iTries = GetLocalInt(oPlayer, "portal_tries");

        if(iTries < iMaxTries)
        {
            //iMaxTries not reached, try again.
            DelayCommand(2.0f, WaitForPortalReady(oPlayer, oPortal, portaldata, sWaypoint));
            if ((iTries % 4) == 0)
                SendMessageToPC(oPlayer, "Trying to send...");
            SetLocalInt(oPlayer, "portal_tries", iTries + 1);
        }
        else
        {
            //iMaxTries reached. Abort.
            SendMessageToPC(oPlayer,
                            "Your character file could not be transferred successfully (still busy). Portalling aborted.");
            DeleteLocalInt(oPlayer, "portal_tries");
            DeleteLocalInt(oPlayer, "VAULTSTER_ID");
        }
    }
    else if (iNWNXStatus == VAULTSTER_STATUS_ERROR)
    {
            //Max number of name variations tried, and/or an error occured.
            //Clear variables and abort.
            SendMessageToPC(oPlayer,
                        "Your character file could not be transferred successfully (an error occured). Portalling aborted.");
            DeleteLocalInt(oPlayer, "portal_tries");
            DeleteLocalInt(oPlayer, "VAULTSTER_ID");
    }
}

void PortalPlayerNWNX(object oPlayer, object oPortal, string sServer, string sWaypoint)
{
    // Verify that player is not already trying to portal.
    if(GetLocalInt(oPlayer, "VAULTSTER_ID") != 0 || GetLocalInt(oPlayer, "portal_attempting") != 0)
    {
        SendMessageToPC(oPlayer, "You attempted to portal too recently, or a portal attempt is still in progress. Please wait 30 seconds and try again.");
    }

    //Make sure the player's BIC file is saved before doing anything else.
    ExportSingleCharacter(oPlayer);

    // Load server information from the database.
    struct ServerData portaldata = LoadServerData(sServer);

    //Prepare the IP for the Job string by removing the port.
    string sServerIP;
    int iPos = FindSubString(portaldata.address, ":");
    if (iPos != -1)
        sServerIP = GetStringLeft(portaldata.address, iPos);

    //Set up the filename to look for, and the current Vaultster job for this player.
    string sFilename = ConvertToFilename(GetName(oPlayer));
    string sJob = sServerIP + "|" + GetPCPlayerName(oPlayer) + "|" + sFilename + "|" + portaldata.vaultport;
    if(sFilename == "" || GetPCPlayerName(oPlayer) == "")
    {
      SendMessageToPC(oPlayer, "There was an error with your data. Please retry.");
      return;
    }
    SetLocalString(GetModule(), "NWNX!VAULTSTER!SEND", sJob);
    SetLocalInt(oPlayer, "VAULTSTER_ID", StringToInt(GetLocalString(GetModule(), "NWNX!VAULTSTER!SEND")) + 1);
    SetLocalInt(oPlayer, "portal_attempting", 1);
    DelayCommand(30.0f, ClearPortalAttemptVar(oPlayer));

    //Start the portalling process.
    SendMessageToPC(oPlayer, "Trying to portal...");
    DelayCommand(5.0f, WaitForPortalReady(oPlayer, oPortal, portaldata, sWaypoint));
}