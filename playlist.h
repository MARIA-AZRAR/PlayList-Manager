#include "song.h"
#include<cstring>
#include<iostream>
#include<string.h>
#include<string>
#include<conio.h>
using namespace std;

class playlist
{
	friend playlist operator+(playlist& p1, const Song& s1);  //ADdition operator       //OPERATO overloading and friend function
	friend playlist operator-(playlist& l2, const Song& s2);  //subtraction

private:

	int m;                     //Variable for memory allocation
	Song * plist;              //Creating pointer for the dynamic memory allocation

	int scounter = 0;       // A counter to keep count of songs
	int capacity = 0;          //A variable to tell capcity of the array
	int index;                  //To tell the idex of current song
public:
	
	
	playlist();         //Default constructor
	void ShowStatus() const;       //Function to show status of the songs array
	void doublesize();
	void addsong(const Song &s);                //Function to add songs to the list
	void ShowAll() const;              //A Function to display all songs
	void play();          //A function to play all songs
	void DeleteSong(const Song &s);     //A FUNCTION TO DELete the selected song
	void halfsize();        //A Function to halfe the size of array




	//MY Functions
	







	~playlist();               //destructor
};
