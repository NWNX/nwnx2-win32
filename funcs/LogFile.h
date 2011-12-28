#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

class LogFile {
public:
	static LogFile &Instance(char *filename) {
		static LogFile theLog(filename);
		return theLog;
	}
	static void LOG(int level, const char *pcMsg, ...);
	
	static void SetDebugLevel(int level);
	static int GetDebugLevel();

private:
	LogFile(char *filename);
	LogFile();
	LogFile(LogFile const&);
	LogFile& operator=(LogFile const&);
	~LogFile();

	static FILE *m_fFile;
	static char acBuffer[];
	
	static int debugLevel;
};

