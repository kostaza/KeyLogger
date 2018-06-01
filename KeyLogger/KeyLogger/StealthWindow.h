#pragma once

#include <Windows.h>

class StealthWindow {
public:
	StealthWindow();
	virtual ~StealthWindow();
private:
	HWND console;
};
