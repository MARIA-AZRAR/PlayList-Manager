#include "playlist.h"
#include "song.h"
#include<iostream>
#include<string.h>
#include<string>
#include<conio.h>
using namespace std;

                /*---------------------------------------------------------------------------------------------------------
                ----------------------------------        DEFAULT CONSTRUCTOR         -------------------------------------
				----------------------------------------------------------------------------------------------------------*/

playlist::playlist()
{      
	                                                        //Default constructor that buits up space for two songs
	m = 2;
	capacity = 2;                                       //capacity of array is 2
	plist = new Song[m];                     //Creating a dynamic memory allocation 
}

				/*---------------------------------------------------------------------------------------------------------
				-------------------------------------          SHOW STATUS        -----------------------------------------
				----------------------------------------------------------------------------------------------------------*/

void playlist::ShowStatus() const                    //Function to show the status of the playlist
{
	cout << "Size of the song array : " << capacity << endl; //this will show total size of array
	cout << "Number of Songs in the playlist : " << scounter << endl;           //this willshow the total number of songs
	cout << "Current song index : " << index << endl;        //this will show current index of the song
}

	
