#include "stdafx.h"
#include "Uploader.h"
#include <iostream>

#define HOST L"ftp.dlptest.com"				// Insert you preferable FTP server here
#define USER L"dlpuser@dlptest.com"			// Insert the username of your FTP server
#define PASS L"eiTqR7EMZD5zy7M"				// Insert the password of your FTP server

Uploader::Uploader() {
	handle = InternetOpen(nullptr, INTERNET_OPEN_TYPE_DIRECT, nullptr, nullptr, 0);
	if (handle == NULL) 
		throw GetLastError();
	session = InternetConnect(handle, HOST, INTERNET_DEFAULT_FTP_PORT, USER, PASS, INTERNET_SERVICE_FTP, INTERNET_FLAG_PASSIVE, 0);
	if (session == NULL) 
		throw GetLastError();
}

Uploader::~Uploader() {
	if (session != NULL)
		if (!InternetCloseHandle(session))
			std::cerr << "Failed to close session. Error: " << GetLastError() << std::endl;
	if (handle != NULL)
		if (!InternetCloseHandle(handle))
			std::cerr << "Failed to close connection. Error: " << GetLastError() << std::endl;
}

void Uploader::upload(const wchar_t *fname) const {
	if (!FtpPutFile(session, fname, fname, FTP_TRANSFER_TYPE_BINARY, 0))
		throw GetLastError();
}