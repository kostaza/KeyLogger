//#define _WIN32_WINNT 0x0500
#include "stdafx.h"
#include "StealthWindow.h"

StealthWindow::StealthWindow() {
	console = GetConsoleWindow();
	if (console)
		ShowWindow(console, SW_HIDE);
}

StealthWindow::~StealthWindow() {
	if (console)
		DestroyWindow(console);
}