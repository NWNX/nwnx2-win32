This is a plugin for NWNX

- Installation
just put the nwnx_reset.dll into your main NWN folder with the NWNX files

- Use
in NWscript call SetLocalString(GetModule(),"NWNX!RESET!SHUTDOWN","1") to shutdown the nwserver process. (note that there has to be a value in the string or the variable doesn't get set and the request won't get processed.

This terminates the NWServer process gracefully, allowing it to shut down the module and save characters, but it does not protect from server hangs during this process.

--
Original plugin by Asmodae
Rewritten by virusman, 2012