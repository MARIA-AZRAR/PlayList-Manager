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
