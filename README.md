# KeyLogger
University project: smart keylogger - records the key strokes when visiting the predefined pages/windows, uploads the records to a predefined FTP server. 

The keylogger is distributed by a malicious word document with an embedded macro.

**DISCLAIMER: This project is for study and practice purposes. Don't use it for any malicious/illegal purposes!**

## KeyLogger module
**_USE WITH CAUTION - may be blocked by antivirus and/or leak you personal data on public internet_**



* The KeyLogger, when not compiled under the _DEBUG_ flag, hides it's own consloe window and runs eternally, monitoring the forground window name.

* When the window name matches on of the predefined names (could be changed inside `Logger.cpp` - inside the `initialize` method), the KeyLogger records the key strokes and saves them loally, until the foreground window is switched.

* Then, the KeyLogger uploads the record to the predefined FTP server (which could be changes inside `Uploader.cpp` - by modifying the `HOST`, `USER` and `PASS` constants). The saved output file is named with a timestamp, in the following format: `keystrokes - %Y%m%d_%H%M%S.txt`



Inside the *KeyLogger/KeyLogger/* folder are the source, header and the project files.

Inside the *KeyLogger/Packed Executable/* folder is the compiled binary of the project, after it was **packed with UPX packer** - in order to make it harder for the antivirus system to detect the binary and to statically analyze it.
