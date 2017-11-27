// Name     : NWNX
// Purpose  : External script demonstration
// Authors  : Ingmar Stieger
// Modified : January 23, 2005

// This file is licensed under the terms of the
// GNU GENERAL PUBLIC LICENSE (GPL) Version 2

void main()
{
    object oPC = GetFirstPC();
    if (GetIsObjectValid(oPC))
        SendMessageToPC(oPC, "Hello from external script!");
    WriteTimestampedLogEntry("Hello from external script!");
}
