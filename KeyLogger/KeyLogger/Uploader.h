#pragma once
#include <Windows.h>
#include <WinInet.h>
#pragma comment(lib, "wininet.lib")

class Uploader {
public:
	Uploader();
	~Uploader();
	void upload(const wchar_t *fname) const;
	
private:
	HINTERNET handle;
	HINTERNET session;
};

