//Justus Stephens
//Game Of Life
//3/17/2019

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//proto

void outputFile(int[][12], int);   //output file
void processGame(int[][12], int[][12]);  //life calcs

ofstream outFile;

int main()
{
	
	outFile.open("GameOfLife.txt");
	outFile << "				        	Justus Stephens         3/17/2019			\n \n";
	
	int array1[12][12] = { 
		{0,0,0,0,0,0,0,0,0,0,0,0},
	    {0,0,0,0,1,0,1,0,1,0,0,0},
	    {0,0,0,1,0,1,0,1,0,0,0,0},
	    {0,0,0,0,0,0,0,0,0,0,0,0},
	    {0,0,0,0,1,0,1,0,1,0,0,0},
	    {0,0,0,1,0,1,0,1,0,0,0,0},
	    {0,1,1,1,1,1,1,1,1,1,1,0},
	    {0,0,0,0,1,1,1,1,0,0,0,0},
	    {0,0,0,0,1,0,1,0,1,0,0,0},
	    {0,0,0,1,0,1,0,1,0,0,0,0},
	    {0,0,0,0,1,0,1,0,1,0,0,0},
	    {0,0,0,0,0,0,0,0,0,0,0,0} };
	    
	int array2[12][12];
	
	for(int cr=0; cr<12; cr++)              //copying the values from array 1 to array 2;
	{
		for(int cc=0; cc<12; cc++)
		{
			array2[cr][cc] = array1[cr][cc];
		}
	}
	
	for(int generations = 1; generations < 5; generations ++)   //loop for number of generations
	{
		processGame(array1, array2);							//doing the calculations
	
		outputFile(array2, generations);						//printing results found in processGame
		
		for(int cr=0; cr<12; cr++)            					//copying the values from array 1 to array 2;
		{
			for(int cc=0; cc<12; cc++)
			{
				array1[cr][cc] = array2[cr][cc];
			}
		}			
	}
	
	outFile.close();		
	cout << "Please see file for results.";
	return 0;
	
}

void processGame(int array1[][12], int array2[][12])
{	
	for(int r = 1; r < 11; r++)			//check rows, but not first or last, they are always zero
	{
		for(int c = 1; c < 11; c++)      //check cols, not first or last
		{
			if(array2[r-1][c-1] + array2[r-1][c] + array2[r-1][c+1] + array2[r][c-1] + array2[r][c+1] + array2[r+1][c-1] + array2[r+1][c] + array2[r+1][c+1] <= 1)
			{
				array2[r][c] = 0;   //less than 1 neighbor == dead
			}
			else if(array2[r-1][c-1] + array2[r-1][c] + array2[r-1][c+1] + array2[r][c-1] + array2[r][c+1] + array2[r+1][c-1] + array2[r+1][c] + array2[r+1][c+1] == 2)
			{
				array2[r][c] = 1;   //less than 4 but not 1 == alive (2 to 3 neighbors)
			}
			else if(array2[r-1][c-1] + array2[r-1][c] + array2[r-1][c+1] + array2[r][c-1] + array2[r][c+1] + array2[r+1][c-1] + array2[r+1][c] + array2[r+1][c+1] == 3)
			{
				array2[r][c] = 1;   //less than 4 but not 1 == alive (2 to 3 neighbors)
			}
			else if(array2[r-1][c-1] + array2[r-1][c] + array2[r-1][c+1] + array2[r][c-1] + array2[r][c+1] + array2[r+1][c-1] + array2[r+1][c] + array2[r+1][c+1] >= 4)
			{
				array2[r][c] = 0;   //4 or more neighbors == dead
			}
		}
	}
	
//	array1 = array2;
	
}


void outputFile(int array2[][12], int generations)
{
	outFile << "                                             Game Of Life Results For Generation: " << generations << "\n\n";
	outFile << "                                         0   1   2   3   4   5   6   7   8   9   10  11                  \n\n\n";
	
	for(int row=0; row<12; row++)
	{
		outFile << "                                   "<< row << "    ";
		
		for(int col=0; col<12; col++)
		{
			outFile << setw(2) << array2[row][col] << "  "; 
		}
		outFile << "\n\n\n";
	}
	
}
