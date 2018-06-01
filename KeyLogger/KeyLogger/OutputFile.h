#pragma once
#include <fstream>
#include <Windows.h>

class OutputFile {
public:
	OutputFile(const char *title);
	virtual ~OutputFile();
	void insert(const char *ch);

private:
	std::ofstream file;
	wchar_t fname[36];
};
