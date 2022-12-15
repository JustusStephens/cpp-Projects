//Justus Stephens
//cps 161
//shell sort assignement
//3/31/19

#include <stdlib.h> // Random 
#include <time.h> 	// Random
#include <iostream>
#include <cwchar> 	//for font
#include <windows.h>//for font 

using namespace std;

//Proto

void fillArray(int[]);
void bubbleSort(int[]);       //do while
void selectionSort(int[]);    //for
void danSort(int[]);          //for
void shellSort(int[]);        //while

int main()
{
	int array[20];
	int sort=-1;
	
	//makes my output pretty
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // width of character
	cfi.dwFontSize.Y = 20;                  // height
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system ("color 04");
	
	
	cout << "				WELCOME TO THE STEPHENS' SUCCULENT SORTER \n\n";
	
	cout << "		Below will be a list of random numbers, how would you like to sort them? \n\n";
	
	while(sort != 1 && sort != 2 && sort != 3 && sort != 4)
	{
		cout <<"						Enter\n					1 for the Bubble sort\n					2 for the Selection sort\n					3 for the Dan sort\n					4 for the Shell sort \n\n";
		cin >> sort;
	}
	
	cout << endl;
	
	fillArray(array);				//filling array with random numbers
	
	if(sort == 1)
	{
		bubbleSort(array);
	}
		
	if(sort == 2)
	{
		selectionSort(array);
	}
		
	if(sort == 3)
	{
		danSort(array);
	}
		
	if(sort == 4)
	{
		shellSort(array);
	}
	
	
	
}

void fillArray(int array[])
{
	for(int f=0; f<20; f++)
	{
		array[f] = rand() % 50 + 1; 											//random 1-50
	}
	
	cout << "					Initial list of values: \n\n			";
	
	for(int print=0; print<20; print++)
	{
		cout << array[print] << " ";
	}
}

void bubbleSort(int array[])
{
	int max=19;
	int i=0;
	
	do
	{
		i=0;
		
		while(i < max)
		{
			if(array[i] > array[i+1])
			{
				int temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
			}
			i++;
		}
		max--;
		
	}while(max > 0);
	
	cout << "\n\n\n				Sorted list of values using the Bubble sort: \n\n			";
	
	for(int print=0; print<20; print++)
	{
		cout << array[print] << " ";
	}
	
	cout << "\n\n\n\n\n";
}

void selectionSort(int array[])
{
	int size = 20;
	
	for(int low=0; low <= size-2; low++)
	{
		for(int up = low+1; up < size; up++)
		{
			if(array[low] < array[up])
			{
				int temp = array[low];
				array[low] = array[up];
				array[up] = temp;
			}
		}
	}
	
	cout << "\n\n\n				Sorted list of values using the Selection sort: \n\n			";
	
	for(int print=0; print<20; print++)
	{
		cout << array[print] << " ";
	}
	
	cout << "\n\n\n\n\n";
}

void danSort(int array[])
{
	int size = 20;
	
	for(int low=0; low <= size-2; low++)
	{
		for(int up = low+1; up < size; up++)
		{
			if(array[low] > array[up])
			{
				int temp = array[low];
				array[low] = array[up];
				array[up] = temp;
			}
		}
	}
	
	cout << "\n\n\n				Sorted list of values using the Dan sort: \n\n			";
	
	for(int print=0; print<20; print++)
	{
		cout << array[print] << " ";
	}
	
	cout << "\n\n\n\n\n";
}

void shellSort(int array[])
{
	int i = 10;
	
	while(i > 0)
	{
		int i2 = i;
		
		while(i2 < 20)
		{
			int i3 = i2-i;
			
			while(i3 >= 0)
			{
				if(array[i3 + i] > array[i3])
				{
					i3 = 0;
				}
				
				else
				{
					int temp = array[i3];
					array[i3] = array[i3+1];
					array[i3+1] = temp;
				}
				
				i3 = i3 - i;
			}
			
			i2++;
		}
		
		i = i/2;
	}
	
	cout << "\n\n\n				Sorted list of values using the Shell sort: \n\n			";
	
	for(int print=0; print<20; print++)
	{
		cout << array[print] << " ";
	}
	
	cout << "\n\n\n\n\n";
	
}
