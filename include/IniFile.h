/***************************************************************************
    IniFile.cpp - interface for the CIniFile class.
    Copyright (C) 2005 Jeroen Broekhuizen (jeroen@nwnx.org) and
	Ingmar Stieger (papillon@nwnx.org)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

 ***************************************************************************/

#if !defined(AFX_INIFILE_H__32EA3A38_50E1_4664_985F_063BC5A23C66__INCLUDED_)
#define AFX_INIFILE_H__32EA3A38_50E1_4664_985F_063BC5A23C66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CIniFile  
{
public:
	CIniFile(LPCSTR lpszFileName);
	virtual ~CIniFile();

	int ReadInteger(LPCSTR lpszSection, LPCSTR lpszKey, int iDefault);
	long ReadLong (LPCSTR lpszSection, LPCSTR lpszKey, long lDefault);
	void ReadString(LPCSTR lpszSection, LPCSTR lpszKey, LPSTR lpszBuffer, int Size, LPCSTR lpszDefault);
	bool ReadBool(LPCSTR lpszSection, LPCSTR lpszKey, bool iDefault);

private:
	char m_szFileName[MAX_PATH];
};

#endif // !defined(AFX_INIFILE_H__32EA3A38_50E1_4664_985F_063BC5A23C66__INCLUDED_)
