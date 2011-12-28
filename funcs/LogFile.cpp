#include "stdafx.h"
#include <stdarg.h>
#include "LogFile.h"
#include <time.h>

FILE *LogFile::m_fFile = NULL;
char LogFile::acBuffer[65535];
int LogFile::debugLevel = 5;


LogFile::LogFile(char *filename) {
	m_fFile = fopen(filename, "w");
}

LogFile::~LogFile() {
	fclose(m_fFile);
}

void LogFile::LOG(int level, const char *pcMsg, ...) {
	if (level <= debugLevel) {
		va_list argList;

		if (m_fFile){
			time_t rawtime;
			time(&rawtime);
			struct tm *ti;
			ti = localtime(&rawtime);
			// build up the string
			va_start(argList, pcMsg);
			vsprintf(acBuffer, pcMsg, argList);
			va_end(argList);

			// _log string in file
			fprintf (m_fFile, "[%02d/%02d/%02d %02d:%02d:%02d] %s", ti->tm_mon+1, ti->tm_mday, ti->tm_year+1900, ti->tm_hour, ti->tm_min, ti->tm_sec, acBuffer);
			fflush (m_fFile);
		}
	}
}

void LogFile::SetDebugLevel(int level) {
	debugLevel = level;
}

int LogFile::GetDebugLevel() {
	return debugLevel;
}