/***************************************************************************
    Server.cpp - Implementation of the Socket class.
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

#include <windows.h>
#include <stdio.h>
#include <io.h>
#include "Sock.h"
#include "Zlib.h"
#include "NWNXVaultster.h"

#define BUF_SIZE 1024

#pragma warning (disable: 4244)

// use this variable for logging purposes
extern CNWNXVaultster vaultster;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

bool CSock::StartWSA ()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int ret;

	wVersionRequested = MAKEWORD( 2, 2 );
	ret = ::WSAStartup (wVersionRequested, &wsaData);
	if (ret != 0) {
		vaultster.Log ("o Failed to start up WinSock!\n");
		return false;
	}
	if (LOBYTE (wsaData.wVersion) != 2 || HIBYTE (wsaData.wVersion) != 2) {
		// user has wrong version of winsock installed
		vaultster.Log ("o Vaultster requires WinSock version 2.2, you have %d.%d installed.\n", wsaData.wVersion, wsaData.wVersion);
		WSACleanup( );
		return false;
	}
	else {
		// initialized correct version of WinSock
		vaultster.Log ("o Using WinSock 2.2.\n");
		return true;
	}
}

CSock::CSock()
{
	m_iSocket = -1;
	m_TV.tv_sec = 10;
	m_TV.tv_usec = 0;
}

CSock::CSock(int iOpenSocket)
{
	m_iSocket = iOpenSocket;
}

CSock::~CSock()
{

}

bool CSock::Create(int iPort)
{
	// create the socket
	m_iSocket = socket (AF_INET, SOCK_STREAM, 0);
	if (m_iSocket < 0)
	{
		int Error = WSAGetLastError ();
		char buffer[256];
		sprintf (buffer, "Socket error: %d", Error);
		MessageBox (NULL, buffer, "CSocket", MB_OK);
		return false;
	}

	if (iPort > 0)
	{
		sockaddr_in server;
		// set up the server structure
		server.sin_family		= AF_INET;
		server.sin_addr.s_addr	= htonl (INADDR_ANY);
		server.sin_port			= htons (iPort);

		// bind the socket to a port
		if (bind (m_iSocket, (sockaddr*)&server, sizeof (server)) == SOCKET_ERROR)
		{
			int Error = WSAGetLastError ();
			char buffer[256];
			sprintf (buffer, "Socket error: %d", Error);
			MessageBox (NULL, buffer, "CSocket", MB_OK);
			return false;
		}
	}

	return true;
}

BOOL CSock::Connect(LPCSTR sServer, UINT iPort)
{
	sockaddr_in server;

	server.sin_family = AF_INET;
	server.sin_port = htons ((u_short)iPort);
	server.sin_addr.s_addr = inet_addr(sServer);

	if (server.sin_addr.s_addr == INADDR_NONE)
	{
		hostent *host_info = gethostbyname (sServer);
		if (host_info == NULL)
			return FALSE;
		memcpy (&server.sin_addr, host_info->h_addr, host_info->h_length);
	}

	// connect to server
	if (connect (m_iSocket, (sockaddr*)&server, sizeof (server)) == SOCKET_ERROR)
		return FALSE;

	return TRUE;
}

void CSock::Close()
{
	// close the socket
	closesocket (m_iSocket);
	m_iSocket = -1;
}

void CSock::Listen(int iConnectionBacklog)
{
	// start listening for pending connections
	listen (m_iSocket, iConnectionBacklog);
}

bool CSock::Accept(CSock &Client, SOCKADDR* lpSockAddr)
{
   int sockAddrLen = sizeof (sockaddr_in);

	// try to accept the connection
	Client.m_iSocket = accept (m_iSocket, lpSockAddr, &sockAddrLen);
	if (Client.m_iSocket < 0)
		return false;
	return true;
}

int CSock::Select(int MaxFd, FD_SET *Read, FD_SET *Write, FD_SET *Except, timeval* tv)
{
	// check if there are any new clients or msg's pending
	return select (MaxFd, Read, Write, Except, tv);
}

int CSock::Send (const void *Data, UINT nSize)
{
   fd_set fd;
   FD_ZERO (&fd);
   FD_SET (m_iSocket, &fd);

   m_TV.tv_sec = 5;
   m_TV.tv_usec = 0;

   if (select (m_iSocket+1, NULL, &fd, NULL, &m_TV) > 0)
	   return send (m_iSocket, (char*)Data, nSize, 0);
   else
      return 0;
}

int CSock::Receive(void *lpBuf, UINT nSize, int Flags)
{
   fd_set fd;
   FD_ZERO (&fd);
   FD_SET (m_iSocket, &fd);

   m_TV.tv_sec = 5;
   m_TV.tv_usec = 0;

   if (select (m_iSocket+1, &fd, NULL, NULL, &m_TV) > 0)
	   return recv (m_iSocket, (char*)lpBuf, nSize, Flags);
   else
      return 0;
}

// use this variable for logging purposes
extern CNWNXVaultster vaultster;

typedef unsigned char uchar;
typedef unsigned long ulong;

BOOL CSock::SendFile (char* File, BOOL bCompress)
{
	uchar* sendData = NULL;
	int actualDataSize = 0, nSend, code;

	// try to open the file
	FILE* f = fopen (File, "rb");
	if (f == NULL)
		return FALSE;

	// determine file size
	fseek (f, 0, SEEK_END);
	int iFileSize = ftell (f);
	fseek (f, 0, SEEK_SET);

	// send original filesize
   if (TIMEOUT (Send (iFileSize))) {
      fclose (f);
		return FALSE;
   }
	actualDataSize = iFileSize;

	if (bCompress)
	{
		// load and compress file data
		uchar* fileData = (uchar*)malloc (iFileSize);
		fread (fileData, 1, iFileSize, f);
		actualDataSize = int(actualDataSize * 1.2f) + 12;
		sendData = (uchar*)malloc (actualDataSize);
		int res = compress2 (sendData, (ulong*)&actualDataSize, fileData, (ulong)iFileSize, Z_DEFAULT_COMPRESSION);
		free (fileData);

      if (res != Z_OK) {
         fclose (f);
			return FALSE;
      }
	}
	else
	{
		// no compression
		sendData = (uchar*)malloc (actualDataSize);
		fread (sendData, 1, actualDataSize, f);
	}

   // no more need of the file
   fclose (f);

	// send the data size
   if (TIMEOUT (Send (actualDataSize))) return FALSE;

   vaultster.TimestampedLog ("o Sending data part of the file (%d bytes).\n", actualDataSize);

	int iSendData = 0, nBytesToSend = 0;
	while (iSendData < actualDataSize)
	{
      // send the data to the server
		nBytesToSend = min (BUF_SIZE, actualDataSize - iSendData);
		nSend = Send (&sendData[iSendData], nBytesToSend);
		if (nSend == SOCKET_ERROR) {
			int error = WSAGetLastError ();
			vaultster.TimestampedLog ("o WinSock error %d!!\n", error);
			return FALSE;
		}
		else if (TIMEOUT (nSend)) {
			vaultster.TimestampedLog ("o Time out during transmission.\n");
			return FALSE;
		}
		else
			vaultster.TimestampedLog ("o Send %d bytes of data.\n", nSend);
		iSendData += nSend;
	}

	free (sendData);
	Receive (code);
	return (bool)code;
}

BOOL CSock::ReceiveFile (char* File, BOOL bCompressed)
{
	int iFileSize, iDataSize, nReceived;

	// receive filesize
	if (TIMEOUT (Receive (iFileSize))) return FALSE;

	// receive actual data size (same if no compression)
	if (TIMEOUT (Receive (iDataSize))) return FALSE;

	// allocate memory for the buffers
	uchar* compressed = (uchar*)malloc (iDataSize);

	int iReceivedData = 0;
	int nBytesToReceive = 0;
	while (iReceivedData < iDataSize)
	{
		// receive data and decrypt if needed
		nBytesToReceive = min (BUF_SIZE, iDataSize - iReceivedData);
		nReceived = Receive (&compressed[iReceivedData], nBytesToReceive);
      if (TIMEOUT (nReceived)) return FALSE;
		iReceivedData += nReceived;
	}

	vaultster.TimestampedLog ("o Receiving file: %s\n", File);

   // try to open the file
	FILE* f = fopen (File, "wb");
   if (f == NULL) {
      // try to create the directory
      char* pos = strrchr (File, '\\');
      pos[0] = 0;

	  vaultster.TimestampedLog ("o Trying to create dir: %s\n", File);

      if (!CreateDirectory (File, NULL)) {
         Send (0);
		   return FALSE;
      }
      
      pos[0] = '\\';
      f = fopen (File, "wb");
      if (f == NULL) {
         Send (0);
         return FALSE;
      }
   }

	if (bCompressed)
	{
		// decompress and store the data in file
		uchar* fileData = (uchar*)malloc (iFileSize);
		uncompress (fileData, (ulong*)&iFileSize, compressed, (ulong)iDataSize);
		fwrite (fileData, 1, iFileSize, f);
		free (fileData);
	}
	else
	{
		// data can be written to the file directly
		fwrite (compressed, 1, iFileSize, f);
	}

	fclose (f);
	free (compressed);

	// signal ready
	Send (1);
	return TRUE;
}

