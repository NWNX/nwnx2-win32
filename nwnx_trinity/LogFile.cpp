#include <stdarg.h>
#include "stdafx.h"
#include "LogFile.h"

FILE *LogFile::m_fFile = NULL;
char LogFile::acBuffer[65535];

LogFile::LogFile(char *filename) {
	m_fFile = fopen(filename, "w");
}

LogFile::~LogFile() {
	fclose(m_fFile);
}

void LogFile::LOG(const char *pcMsg, ...) {
	va_list argList;

	if (m_fFile){  
		// build up the string
		va_start(argList, pcMsg);
		vsprintf(acBuffer, pcMsg, argList);
		va_end(argList);

		// _log string in file
		fprintf (m_fFile, acBuffer);
		fflush (m_fFile);
	}
}