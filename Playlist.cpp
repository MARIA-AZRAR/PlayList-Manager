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

						/*---------------------------------------------------------------------------------------------------------
						----------------------------------------       ADD SONG       ---------------------------------------------
						----------------------------------------------------------------------------------------------------------*/

void playlist::addsong(const Song &s)                   //Function to add song
{
	if (capacity == scounter)
	{
		
		doublesize();           //Calling the double size function if there is no capacity in current array
		plist[scounter] = s;    //storing in the next index
		scounter++;             //incrementing the number of songs
	}
	else                          //if the size of the current array is enough then
	{
		plist[scounter] = s;         //assigning value to the song playlist
		scounter++;                   //incrementing the number of songs
	}
	index = scounter;
}
					/*---------------------------------------------------------------------------------------------------------
					--------------------------------------------      SHOW ALL      --------------------------------------------
					----------------------------------------------------------------------------------------------------------*/


void playlist::ShowAll() const                     //Function to show all songs
{
	cout << endl << "SONG NAME , ARTIST NAME" << endl; //Artist name and song name
	for (int i = 0; i < scounter; i++)          //loop to show all songs
	{
		cout << plist[i];
		cout << endl;
	}
	
}
					/*---------------------------------------------------------------------------------------------------------
					--------------------------------------------     PLAY     -------------------------------------------------
					----------------------------------------------------------------------------------------------------------*/


void playlist::play()          //A function to play all songs
{
	char x;                    // variable to aska if user want to repeat the list
	while (1)                  //this will become an infinite loop so it will play continously
	{
		cout << "IF you want to continue or terminate the loop press y/n" << endl;
		cin >> x;
		if(x=='y')       //check if we want to play song
	
			for (int i = 0; i < scounter; i++)
			{
				cout << "Playing Song : " << plist[i]<<endl;
			}
		else
		{
			break;
		}
	}
	
}

					/*---------------------------------------------------------------------------------------------------------
					-----------------------------------            DELETE SONG             ------------------------------------
					----------------------------------------------------------------------------------------------------------*/

void playlist::DeleteSong(const Song &s)     //A FUNCTION TO DELete the selected song
{

	int l = -1;   //in case if song is not present
	int i;     //loop and index variable
	for (i = 0; i < scounter; i++)      //loop to find the index of song
	{ 

		if (plist[i] == s)    //checking if song is the 
		{
		

			l = 0;
			break;
		}
		
	}
	if (l == -1)
	{
		cout << "Song not present" << endl;
	}
	else if (l == 0)
	{
		for (; i < scounter - 1; i++)               //use of song set function to set values to default
		{
			plist[i] = plist[i + 1];
		}
		scounter--;
	}
    
	if ((scounter) < (capacity / 2)) //if songs in list are less then half of te capacity of the array
	{
		
		halfsize();
	}
	index = scounter;
}
					/*---------------------------------------------------------------------------------------------------------
					-------------------------------------              HALF SIZE             ----------------------------------
					----------------------------------------------------------------------------------------------------------*/


void playlist::halfsize()
{
	if (capacity == 2)
	{                             //if capacity is default then no change is made
		return;
	}
	else
	{
		//.........STEP 1............

		Song * p2 = new Song[capacity / 2];             //Creating a new array dynamically doubling the size of the current array 

		//.........STEP 2.............

		for (int i = 0; i < scounter; i++)         //Assigning Old array to a new array
		{
			p2[i] = plist[i];
		}

		//........STEP 3.............           

		delete[] plist;                //freeing the old array by deleting it

		//.........STEP 4...........

		plist = p2;              //Setting plist to the new array

		capacity = capacity / 2;        //doubling the variable as we are doubling the size of array we are doing it now cuz we had to copy the old into new and old's capacity is less thats why we double it later on
	}
}

					/*---------------------------------------------------------------------------------------------------------
					---------------------------------              ADDITION OPERATOR            -------------------------------
					----------------------------------------------------------------------------------------------------------*/

playlist operator+(playlist& p1 ,const Song& s1)         //OPERATO overloading and friend function
{
	playlist l1;
    p1.addsong(s1);                    //calling add song function
	l1 = p1;
	return l1;
}

					/*---------------------------------------------------------------------------------------------------------
					---------------------------------           SUBTRACTION OPERATOR            -------------------------------
					----------------------------------------------------------------------------------------------------------*/

playlist operator-(playlist& l2, const Song& s2)  //subtraction
{
	playlist l;
	l2.DeleteSong(s2);           //calling delete song function 
	l = l2;
	return l;
}


