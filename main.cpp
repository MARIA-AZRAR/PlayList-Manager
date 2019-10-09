#include "song.h"
#include "playlist.h"
#include<string.h>
#include<iostream>
#include<conio.h>

using namespace std;


int main()

{
	cout << "                   ----------------------------WELCOME TO PLAYLIST MANAGER----------------------------                    " << endl;
	cout << "                                                        BY MARIA AZRAR                                                      " << endl;
	int input;     //variable for choosing input
	Song S;   //song object for input and del
	playlist play1;
	while (1)
	{
		
		cout << endl << "Choose the following option" << endl;
		cout << "1     Play Songs" << endl;
		cout << "2     Add Song" << endl;
		cout << "3     Delete Course" << endl;
		cout << "4     Show Status" << endl;
		cout << "5     Show All" << endl;
		cout << "6     Exit Program" << endl;

		cin >> input;
		switch (input)
		{
		case 1:
		{
			play1.play();
			break;

		}
		case 2:
		{
			cout << "Enter the song to Add in the format [song name , artist name]" << endl;
			cin >> S;
			play1.addsong(S);
			break;

		}
		case 3:
		{
			cout << "Enter the song to Delete in format [song name , artist name]" << endl;
			cin >> S;
			play1.DeleteSong(S);
			break;

		}
		case 4:
		{
			play1.ShowStatus();
			break;
		}
		case 5:
		{
			play1.ShowAll();
			break;
		}
		case 6:
		{
			exit(0);
		}
	Default:
		{
			cout << "Invalid Choice " << endl;
		}

		}

		
	}
	system("pause");
}
