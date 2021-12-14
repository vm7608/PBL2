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
			application.searchWordInDictionary();
			check = toContinue();
			if (check == 1) goto SEARCH;
			if (check == 2) goto MENU;
			break;
		}
		case 2:
		{
			ADD:
			application.addNewWordToDictionary();
			check = toContinue();
			if (check == 1) goto ADD;
			if (check == 2) goto MENU;
			break;
		}
		case 3:
		{
			DEL:
			application.delWordFromDictionary();
			check = toContinue();
			if (check == 1) goto DEL;
			if (check == 2) goto MENU;
			break;
		}
		case 4:
		{
			EDIT:
			application.editWordInDictionary();
			check = toContinue();
			if (check == 1) goto EDIT;
			if (check == 2) goto MENU;
			break;
		}
		case 5:
		{
			GAME:
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
	application.updateToFile();
	exitScreen();
	return 0;
}
