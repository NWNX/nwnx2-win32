#include "stdafx.h"
#include "nwnx_funcs.h"
#include "../NWNXdll/IniFile.h"
#include <time.h>

#include <stdlib.h>
#include <string.h>

#define _log(a,b,...) if(a<=debugLevel)LOG(b,__VA_ARGS__)

CNWNXFuncs::CNWNXFuncs() {
	getFirstNextEffect = NULL;
}

CNWNXFuncs::~CNWNXFuncs() {
	delete FunctionHooks;
	OnRelease();
}

char* CNWNXFuncs::OnRequest(char *gameObject, char* Request, char* Parameters) {
	oObject = gameObject; Params = Parameters;
	SetParameters();

	_log(1, "- StrReq: \"%s\"           Params: \"%s\"\n", Request, Parameters);

	if (gameObject == NULL || (CGenericObject*)gameObject == NULL) {
		_log(1, "o Error: Invalid Object passed to nwnx_funcs.\n");
		sprintf(Params, "");
		return NULL;
	}

	stdext::hash_map<std::string, int>::iterator it;
	it = FunctionLookup.find(Request);
	if (it != FunctionLookup.end()) {
		(*this.*pFunc[it->second])();
	}
	else if (strcmp(Request, "GETLOCALVARBYPOSITION") == 0) GetLocalVariableByPosition();
	else if (strcmp(Request, "SETEFFECTCREATORBYEFFECTID") == 0) SetEffectCreatorByEffectID();
	else if (strcmp(Request, "SETEFFECTSPELLIDBYEFFECTID") == 0) SetEffectSpellIDByEffectID();
	else if (strcmp(Request, "SETWORLDTIME") == 0) nwn_SetWorldTime(P1, P2, P3);

	else {sprintf(Parameters, "-1"); _log(1, "o Could not find requested function.\n");}

	return NULL;
}

unsigned long CNWNXFuncs::OnRequestObject (char *gameObject, char* Request){
	_log(1, "- ObjReq: %08X             Request: %s\n", gameObject, Request);
	uint32_t ret = OBJECT_INVALID;

	std::string sRequest = Request;
	std::string TrueRequest, Param;
	int i=0;

	if (strcmp(Request, "GETFIRSTAREA") == 0) ret = GetFirstArea();
	else if (strcmp(Request, "GETNEXTAREA") == 0) ret = GetNextArea();
	else if ((i = sRequest.find("¬")) != std::string::npos) {
		TrueRequest = sRequest.substr(0, i++); Param = sRequest.substr(i, sRequest.size()-i);

		if (strcmp(TrueRequest.c_str(), "GETAREABYPOSITION") == 0) ret = GetAreaByPosition(atoi(Param.c_str()));
		if (strcmp(TrueRequest.c_str(), "STRINGTOOBJECT") == 0) {
			ret = StringToObject(Param.c_str());
		}
	}

	else ret = OBJECT_INVALID;

	return ret;
}


void CNWNXFuncs::LOG(const char *pcMsg, ...) {
	va_list argList;
	char *pos;

	if (m_fFile)
	{  

		if (ftell(m_fFile) > m_maxLogSizeKB)
		{	
			fclose(m_fFile);
			m_fFile = fopen (m_LogFile, "w");
			WriteLogHeader(debugLevel);
			fprintf(m_fFile, "o Logfile hit maximum size limit, starting again.\n");
		}

		// build up the string
		va_start(argList, pcMsg);
		vsprintf(acBuffer, pcMsg, argList);
		va_end(argList);

		// replace any percent signs
		pos = strchr(acBuffer, '%');
		while (pos)
		{
			*pos = '~';
			pos = strchr(acBuffer, '%');
		}

		// _log string in file
		time_t rawtime;
		time(&rawtime);
		struct tm *ti;
		ti = localtime(&rawtime);

		fprintf (m_fFile, "[%02d/%02d/%02d %02d:%02d:%02d] %s", ti->tm_mon+1, ti->tm_mday, ti->tm_year+1900, ti->tm_hour, ti->tm_min, ti->tm_sec, acBuffer);
		//fprintf (m_fFile, acBuffer);
		fflush (m_fFile);
	}
}

BOOL CNWNXFuncs::OnCreate(const char* LogDir) {
	// call the base class function
	char _log[MAX_PATH];
	sprintf (_log, "%s\\nwnx_funcs.txt", LogDir);
	if (!CNWNXBase::OnCreate(_log))
		return false;

	CIniFile iniFile ("nwnx.ini");
	debugLevel = iniFile.ReadInteger("FUNCS", "DebugLevel", 0);
	nSkill = iniFile.ReadInteger("FUNCS", "Number_of_Skills", 28);
	bHookCreateGeometry = iniFile.ReadInteger("FUNCS", "HOOK_CustomTrapGeometry", 0);
	bOverrideMaximumDexMod = iniFile.ReadInteger("FUNCS", "HOOK_OverrideMaximumDexMod", 0);
	if ((bHookRemovePCFromWorld = iniFile.ReadInteger("FUNCS", "HOOK_OnPlayerLeaving", 0))) {
		iniFile.ReadString("FUNCS", "OnPlayerLeavingScript", OnPlayerLeavingScript, 16, "onplayerleaving");
	}

	WriteLogHeader(debugLevel);
	CreateFunctionLookup();
	FunctionHooks = new CHookFunctions(debugLevel);

	AbsoluteCoordinates = 0;

	return true;
}

BOOL CNWNXFuncs::OnRelease() {
	FunctionLookup.clear();
	LOG("o Shutting down\n");

	// call base class function
	return CNWNXBase::OnRelease();
}

void CNWNXFuncs::WriteLogHeader(int debug)
{
	fprintf(m_fFile, "Windows NWNX Funcs plugin v.0.0.8.4");
	if (!debug) fprintf(m_fFile, " [logging off]");
	else fprintf(m_fFile, " [log level: %i]", debug);
	fprintf(m_fFile, "\n");
	fflush (m_fFile);
}

void CNWNXFuncs::SetParameters() {
	P1=0; P2=0; P3=0; P4=0;

	if (strcmp(Params, "-") != 0 && strlen(Params) > 0) {
		int i=0;
		int iP=0;
		 while (i<strlen(Params)) {
			 if (Params[i++] == ' ') ++iP;
		 }

		 switch (iP) {
			 case 0: P1 = atoi(Params); break;
			 case 1: sscanf(Params, "%d %d", &P1, &P2); break;
			 case 2: sscanf(Params, "%d %d %d", &P1, &P2, &P3); break;
			 case 3: sscanf(Params, "%d %d %d %d", &P1, &P2, &P3, &P4); break;
		 }
	}
}


char* CNWNXFuncs::GetScriptVarType(int i) {
	switch(i) {
		case 1: return "INT"; break;
		case 2: return "FLT"; break;
		case 3: return "STR"; break;
		case 4: return "OID"; break;
		case 5: return "LOC"; break;
	}
	//_log(2, "o !!!Error!!! GetScriptVarType: Could not determine local variable type!\n");
	return "unknown";
}

CNWSScriptVarTable* CNWNXFuncs::GetVarTable() {
	switch(((CGenericObject*)oObject)->obj_type) {
		case OBJECT_TYPE_AREA: { //Area
			return &((CNWSArea*)oObject)->area_vartable;
		} break;
		case OBJECT_TYPE_MODULE: { //Module
			return &((CNWSModule*)oObject)->mod_vartable;
		} break;
		default: {	//creature, item, placeable, etc
			return &((CNWSObject*)oObject)->obj_vartable;
		} break;
	}
	//_log(2, "o Error: Could not determine ScriptVarTable for object type: %08X\n", ((CGenericObject*)gameObject)->obj_type);
	return NULL;
}

CNWSStats_Level *CNWNXFuncs::nwn_GetLevelStats (const CNWSCreatureStats *stats, int level) {
    if (level < 1 || level > stats->cs_levelstat.len)
        return NULL;

    return (CNWSStats_Level*)stats->cs_levelstat.data[level - 1];
}


BOOL CNWNXFuncs::GetIsCreature() {
	return ((CGenericObject*)oObject)->obj_type == OBJECT_TYPE_CREATURE;
}

BOOL CNWNXFuncs::GetIsItem() {
	return ((CGenericObject*)oObject)->obj_type == OBJECT_TYPE_ITEM;
}

BOOL CNWNXFuncs::ValidEffectObject() {
	switch (((CGenericObject*)oObject)->obj_type) {
		case OBJECT_TYPE_CREATURE:
		case OBJECT_TYPE_ITEM:
		case OBJECT_TYPE_PLACEABLE:
		case OBJECT_TYPE_DOOR:
		return 1;
	}
	return 0;
}

void CNWNXFuncs::NWN_CreateGeometry(CNWSTrigger *Trigger, CScriptLocation *Loc, CNWSArea *Area) {
	Vector *Position;
	Vector *v8;
	int nVertex;
	Vector *v10;

	int nCoordinates = (Floats.size() / 2)+1; // Loc holds the first coordinate

	Position = Trigger->geometry_vectors;
	Trigger->VerticesCount = nCoordinates;
	Trigger->Geometry_len = nCoordinates;
	if ( Position )	{
		delete[] Position;
		Trigger->geometry_vectors = 0;
	}
	if ( Trigger->Vertices ) {
		delete[] Trigger->Vertices;
		Trigger->Vertices = 0;
	}

	if ( Area && !Floats.empty()) {
		float x, y;

		v8 = new Vector[nCoordinates];
		// zero all coords
		if ( v8 ) {
			v10 = (Vector *)((char *)v8 + 8);
			nVertex = nCoordinates;
			do {
				*((DWORD *)v10 - 2) = 0;
				*((DWORD *)v10 - 1) = 0;
				v10->x = 0;
				++v10;
				--nVertex;
			}
			while ( nVertex );
		}
		else {
			v8 = 0;
		}

		Trigger->geometry_vectors = v8;
		Trigger->Vertices = new unsigned int[4*nCoordinates];// Why times 4?

		Trigger->geometry_vectors[0].x = Loc->loc_position.x;
		Trigger->geometry_vectors[0].y = Loc->loc_position.y;
		Trigger->geometry_vectors[0].z = Area->ComputeHeight(
			Trigger->geometry_vectors[0].x,
			Trigger->geometry_vectors[0].y,
			Trigger->geometry_vectors[0].z);
		Trigger->Vertices[0] = 0;

		int i=1;
		std::list<float>::iterator it = Floats.begin();
		while (it != Floats.end()) {
			x = *it + !AbsoluteCoordinates * Loc->loc_position.x;
			it++;
			y = *it + !AbsoluteCoordinates * Loc->loc_position.y;
			it++;



			Trigger->geometry_vectors[i].x = x;
			Trigger->geometry_vectors[i].y = y;
			Trigger->geometry_vectors[i].z = Area->ComputeHeight(
				Trigger->geometry_vectors[i].x,
				Trigger->geometry_vectors[i].y,
				Trigger->geometry_vectors[i].z);
			Trigger->Vertices[i] = i;

			++i;
		}
	}
}

int CNWNXFuncs::SetDebugLevel() {
	debugLevel = P1;
	return 1;
}

int CNWNXFuncs::GetEventScriptInfo(int &ScriptNumber, std::string &ScriptName, int Max) {
	if (strlen(Params) > 0) {
		std::string Param = Params;
		int Space;
		if ((Space = Param.find(" ")) != std::string::npos) {
			if (Param.length() > Space+1) {
				std::string Script = Param.substr(Space+1, std::string::npos);
				Param = Param.substr(0, Space);
				int iScript = atoi(Param.c_str());

				if (iScript >= 0 && iScript <= Max) {
					CExoString sScriptName(Script.c_str());
					sScriptName.StripNonAlphaNumeric(1, 0, 0);
					Param = sScriptName.text;
					Param = Param.substr(0, 16);

					ScriptNumber = iScript;
					ScriptName = Param;
					return 1;
				}
			}
		}
	}
	ScriptNumber = atoi(Params);
	return 1;
}