#include "stdafx.h"
#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

bool isWorking = false;
const int lengthArr = 165;
string WordListArray[lengthArr];

void writeKey(char a)
{
	// Simulate a key press with char
	keybd_event(VkKeyScanEx(TCHAR(a), 0),
		0x45,
		KEYEVENTF_EXTENDEDKEY | 0,
		0);
}

void GetWordlist() {

	//If txt file not found please change the location
	ifstream file("Wordlist.txt");

	//Get all words and put them in the array
	if (file.is_open()) {
		for (int i = 0; i < lengthArr; i++) {
			file >> WordListArray[i];
			cout << WordListArray[i] << endl;
		}
	}
	else {
		cout << "Wordlist not found" << endl;
		Sleep(2000);
	}
}

void main()
{
	GetWordlist();

	while (true) {

		//F9 - START KEY
		if (GetKeyState(VK_F9) < 0) {
			isWorking = true;
		}

		//F10 - STOP KEY (buggy, if you want to stop it, close the program itself)
		if (GetKeyState(VK_F10) < 0) {
			isWorking = false;
		}

		if (isWorking) {

			//For all word in the list
			for (int i = 0; i < lengthArr; i++) {
				//And for all characteres in the word
				for each(char i in WordListArray[i]) {
					//press the key
					writeKey(i);
					Sleep(1);
				}

				//Return key - Word finish written
				keybd_event(0x0D, 0x45, KEYEVENTF_EXTENDEDKEY | 0, 0);
			}

		}

	}

}

