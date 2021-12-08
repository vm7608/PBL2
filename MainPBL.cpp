#include <iostream>
#include "Dict.h"
#include "Format.h"
using namespace std;

int main()
{
	setMode();
	welcomeScreen();
	pause();

	word temp;
	int check;
	dictionary application;

	MENU:
	int userSelection = selectMenu();
	switch (userSelection)
	{
		case 1:
		{
			SEARCH:
			pause();
			application.searchWordInDictionary();
			check = toContinue();
			if (check == 1) goto SEARCH;
			if (check == 2) goto MENU;
			break;
		}
		case 2:
		{
			ADD:
			pause();
			application.addNewWordToDictionary();
			check = toContinue();
			if (check == 1) goto ADD;
			if (check == 2) goto MENU;
			break;
		}
		case 3:
		{
			DEL:
			pause();
			application.delWordFromDictionary();
			check = toContinue();
			if (check == 1) goto DEL;
			if (check == 2) goto MENU;
			break;
		}
		case 4:
		{
			EDIT:
			pause();
			application.editWordInDictionary();
			check = toContinue();
			if (check == 1) goto EDIT;
			if (check == 2) goto MENU;
			break;
		}
		case 5:
		{
			GAME:
			pause();
			application.playGame();
			check = toContinue();
			if (check == 1) goto GAME;
			if (check == 2) goto MENU;
			break;
		}
		case 6:
		{
			break;
		}
	}
	clrscr();
	pause();
	application.updateToFile();
	exitScreen();
	return 0;
}
