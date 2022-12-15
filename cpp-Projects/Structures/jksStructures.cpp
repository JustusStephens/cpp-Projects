#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>			//for system clear
#include <limits>			//for enter to continue
#include <cwchar> 			//for font
#include <windows.h>		//for font 

using namespace std;

void displayMenu();			//displays menu
void userInput(char &);		//gets input
void emptySeats();			//displays empty seats
void numeric();				//displays seat num and passenger names
void alphabetic();			//Couldn't get this, so I just did size of last name
void assign(int &);			//assigns a seat
void cancel(int &);			//cancels a reservation
void clear();				//clears screen

struct passenger
{
	int seatNum=0;			//seat number
	string first;		//first name
	string last;		//last name
	bool fill = false;		//seat fill t or f
}person[12+1];

int main()
{
	
		//makes my output pretty
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // width of character
	cfi.dwFontSize.Y = 20;                  // height
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system ("color 05");
	
	char letter = 'z';
	int passengerCount=1;			//only manipulated in assign() and cancel();
	
	while(letter!='f')
	{
		char wait = 'w';
		displayMenu();
		
		userInput(letter);
	//	cout << "letter: " << letter;
		
		if(letter == 'a')
		{
			clear();
			emptySeats();
			
			cout << "\n\n\n					  Please press enter to continue ";
			cin.sync();
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			clear();
		}
		else if(letter == 'b')
		{
			clear();
			numeric();
			cout << "\n\n\n					  Please press enter to continue ";
			cin.sync();
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			clear();
		}
		
		else if(letter == 'c')
		{
			clear();
			alphabetic();
			cout << "\n\n\n					  Please press enter to continue ";
			cin.sync();
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			clear();
		}
		
		else if(letter == 'd')
		{
			clear();
			assign(passengerCount);
			cout << "\n\n\n					  Please press enter to continue ";
			cin.sync();
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			clear();
		}
		
		else if(letter == 'e')
		{
			clear();
			cancel(passengerCount);
			cout << "\n\n\n					  Please press enter to continue ";
			cin.sync();
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			clear();
		}
		
		else
			letter = 'f';
	}
}

void displayMenu()
{
	cout << "					  Welcome to Podunk Airlines\n";
	cout << "\n\n\n";
	cout << "			Please enter a character, (a-f), to choose from the menu options below\n\n\n";
	
	cout << "				a] Count of Empty Seats\n";
	cout << "				b] Seats and Passenger Names in Numeric Order\n";
	cout << "				c] Seats and Passenger Names in Alphabetical Order\n";
	cout << "				d] Assign a Passenger to a Seat\n";
	cout << "				e] Cancel Seat Reserveation\n";
	cout << "				f] Quit\n";
}

void userInput(char & letter)
{
	cout  << "\n" <<"				";
	cin >> letter;
	letter = tolower(letter);
}

void emptySeats()
{
	cout << "\n\n					 The Empty Seats are as Follows: \n\n";
	for(int x=1; x<13; x++)
	{
		if(person[x].fill == false)
			cout << "					" << x << " 	";
		if(x%2 == 0)
			cout << "\n";
		
	}
}

void numeric()
{
		cout << "\n\n				The Seats In Numeric Order and Their Assigned Passengers: \n\n";
	for(int x=1; x<13; x++)
	{
		cout << "					Seat #" << x << ": " << person[x].first << " " << person[x].last << endl;
	}
}


void clear()
{
	system("cls");
}


void alphabetic()
{
	string sort[12+1];
	string name;
	bool swap = true;
	int r=0;
	string temp;
	
	for(int x=1; x<13; x++)				//assiging the first character of a last name into my name array
	{
		sort[x] = person[x].last;
	}
	
	while(swap)
	{
		swap = false;
		r++;
		for(int q=1; q < 13-r; q++)
		{
			if(sort[q].compare(sort[q+1]))
			{
				temp = sort[q];
				sort[q] = sort[q+1];
				sort[q+1] = temp;
				swap = true;
			}
		}
	}
	
		cout << "\n\n					 The Passengers in Alphabetical Order: \n\n";
	
	for(int print = 12; print>0; print--)
	{
		cout <<"					" << sort[print] << endl;
	}
}

void assign(int & passengerCount)
{
	int num;
	bool good = true;
	cout << "\n\n					 You have begun the seat assigning process \n\n";
	cout << "					Please enter the seat number you wish to have \n";
	cout << "					";
	cin >> num;
	
	for(int check=1; check<13; check++)
	{
		if(person[check].seatNum==num)
		{
			cout << "					 Sorry, this seat is taken please press enter to continue \n";
			cin.sync();
			cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
			clear();
			good = false;
			assign(passengerCount);
		}
	}
	
	if(good == true)			//if seat taken then good prevents rewrite
	{
	
	cout << "						You have selected seat number: " << num << "\n\n";
	
	cout << "					Please enter the first name of the passenger \n\n";
	cout << "					";
	cin >> person[num].first;
	cout << "\n					Please enter the last name of the passenger \n\n";
	cout << "					";
	cin >> person[num].last;
	person[num].seatNum = num;					//assigns seat num
	person[num].fill = true;
	
	passengerCount++;
	}
	
}

void cancel(int & passengerCount)
{
	char letter;
	string first;
	string last;
	int seatNum;
	
		cout << "\n\n					 You have begun the cancelation process \n\n";
		cout << "				      	     Would you like to cancel by \n\n";
		cout << "						a] name \n";
		cout <<"						b] seat number \n";
		
		while(letter!= 'a' && letter!= 'b')
		{
			cout  << "\n";
			cin >> letter;
			letter = tolower(letter);
		}
		
		if(letter == 'a')
		{
			cout << "\n					Please enter the first name of the canceling passenger \n\n";
			cout << "					";
			cin >> first;
			cout << "\n					Please enter the last name of the canceling passenger \n\n";	
			cout << "					";
			cin >> last;
			
			for(int x=1; x<13; x++)
			{
				if(first == person[x].first && last == person[x].last)
				{
					person[x].last = "";
					person[x].first = "";
					person[x].seatNum = 0;
					passengerCount--;
					person[x].fill = false;
				}
			}
		}
		
		else
		{
			cout << "\n					Please enter the seat number you would like to cancel \n\n";
			cout << "					";
			cin >> seatNum;
			
			for(int x=1; x<13; x++)
			{
				if(seatNum == person[x].seatNum)
				{
					person[x].seatNum = 0;
					person[x].last = "";
					person[x].first = "";
					passengerCount--;
					person[x].fill = false;
				}
			}
			
		}
		
}

