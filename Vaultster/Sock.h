/***************************************************************************
    Sock.h - Definition of the Socket class.
    Copyright (C) 2004 Jeroen Broekhuizen (nwnx@jengine.nl)
    
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

#if !defined(AFX_SOCK_H__80B4EB7D_F1E7_49A7_A790_43369704CB85__INCLUDED_)
#define AFX_SOCK_H__80B4EB7D_F1E7_49A7_A790_43369704CB85__INCLUDED_

#include <winsock.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define TIMEOUT(Status) ((int)(Status) == 0)

class CSock  
{
public:	
	CSock();
	CSock(int OpenSocket);
	virtual ~CSock();

	bool Create (int Port = 0);
	BOOL Connect (LPCSTR Server, UINT Port);
	void Close ();

	static bool StartWSA ();

	void Listen (int ConnectionBacklog = 5);
	bool Accept (CSock& Client, SOCKADDR* SockAddr = NULL);
	int Select (int MaxFd, FD_SET* Read, FD_SET* Write, FD_SET* Except, timeval* tv = NULL);

	int Receive (void* Buf, UINT Size, int Flags = 0);
	int Send (const void* Data, UINT Size);

	inline int Receive (int& value) { return Receive (&value, sizeof (int)); }
	inline int Send (const int value) { return Send (&value, sizeof (int)); }

	BOOL ReceiveFile (char* File, BOOL bCompressed = TRUE);
	BOOL SendFile (char* File, BOOL bCompress = TRUE);

	int ToInt() { return m_iSocket; }
	operator int() const;

private:
	TIMEVAL m_TV;
	int m_iSocket;
};

inline CSock::operator int () const
{
	 return m_iSocket;
}

#endif // !defined(AFX_SOCK_H__80B4EB7D_F1E7_49A7_A790_43369704CB85__INCLUDED_)
