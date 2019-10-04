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

	
				/*---------------------------------------------------------------------------------------------------------
				--------------------------------------         DOUBLE SIZE        -----------------------------------------
				----------------------------------------------------------------------------------------------------------*/

void playlist::doublesize()
{

	//.........STEP 1............

	Song * p1 = new Song[capacity * 2];             //Creating a new array dynamically doubling the size of the current array 

	//.........STEP 2.............

	for (int i = 0; i < capacity; i++)         //Assigning Old array to a new array
	{
		p1[i] = plist[i];
	}

	//........STEP 3.............           

	delete[] plist;                //freeing the old array by deleting it

	//.........STEP 4...........

	plist = p1;              //Setting plist to the new array

	capacity = capacity * 2;        //doubling the variable as we are doubling the size of array we are doing it now cuz we had to copy the old into new and old's capacity is less thats why we double it later on 

}

