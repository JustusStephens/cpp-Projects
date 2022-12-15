//Assignment 5
//Justus Stephens
//February 21, 2019

#include <iostream>
#include <fstream>          //Reading and writing files
#include <iomanip>          //Decimal precision
#include <string>
#include <sstream>          //So i can split my strings into ints


using namespace std;

void outputFile(int &, int&, int &, int &, int &, int &);
void getFractions(int &, int &, int &, int &);
void addFractions(int &, int &, int &, int &);
void simplifyFractions(int &, int &);

ofstream outFile;

int main()
{	
	int n1,d1,n2,d2;              //All of my ints for the fractions
	
	outFile.open("Assignment5Answers.txt");
	outFile << "					Justus Stephens Assigment 5 Answers			\n \n";
	
	getFractions(n1,d1,n2,d2);    //Get the ints here, other functionc also called in this function
		
	outFile.close();		
	cout << "Please see file for results.";
	return 0;
}

void getFractions(int &n1, int &d1, int &n2, int &d2)
{
	int number;
	string line;	
	ifstream inFile ("P5Fractions.txt");
	
	if(inFile.is_open())
	{
		while( getline (inFile,line) )
		{
			
			stringstream ss(line);
			int n1; ss >> n1;    //Numerator 1
			int d1; ss >> d1;    //Denom 1
			int n2; ss >> n2;    //Numerator 2
			int d2; ss >> d2;    //Denom 2
			
			addFractions(n1, d1, n2, d2);	

		}
		
	}
	
    else   //Unable to open file, you go here
	cout << "Unable to open file: P5Fractions.txt";
}

void addFractions(int &n1, int &d1, int &n2, int &d2)
{
	int numSum = 0;
	int denomSum = 0;
	
	numSum = (d2*n1) + (d1*n2);
	denomSum = (d2*d1);
	
	simplifyFractions(numSum, denomSum);
		
	outputFile(n1,d1,n2,d2,numSum,denomSum);
	
}

void simplifyFractions(int &numSum, int &denomSum)
{
  //Euclidan Algo Time a will be the larger number, b the smaller
  int a = numSum;
  int b = denomSum;
  int gcf;
  int remainder;
  
  if(b > a)          //To ensure that a is greater than or equal to b
  {
  	a = denomSum;
  	b = numSum;
  }
  
  
  if(b == 0)
  {
  	gcf = a;
  }
  
  else
  {
  	while (b != 0)
	  {
  		remainder = a % b;
  		a = b;
  		b = remainder;
  	
 	  }
 	  
 	  gcf = a;
  	
  }
  
  	numSum = numSum / gcf;
  	denomSum = denomSum / gcf;
  
}

void outputFile(int &n1, int &d1, int &n2, int &d2, int &numSum, int &denomSum)
{
	int mixed;
	bool specialCase = false;
	
	if(n1 < 0 & d1 < 0)            //2 negatives make a positive
	{
		d1 *= -1;
		n1 *= -1;
	}
	
	if(n2 < 0 & d2 < 0)
	{
		d2 *= -1;
		n2 *=-1;
	}
	
	if(numSum < 0 & denomSum < 0)
	{
		numSum *= -1;
		denomSum *= -1;
	}
	
	if(d1 < 0 & n1 > 0)           //Negatives in bottom go to top
	{
		d1 *= -1;
		n1 *= -1;
	}
	
	if(n2 >0 & d2 < 0)
	{
		d2 *= -1;
		n2 *=-1;
	}
	
	if(numSum > 0 & denomSum < 0)
	{
		numSum *= -1;
		denomSum *= -1;
	}
	
	if(denomSum == 1)
	{
		outFile << setw(33) << n1  << setw(1) << "/" << setw(1) << d1 << setw(12) << "+" << setw(12) << n2 << setw(1) << "/" << setw(1) << d2 << setw(12) << "=" << setw(12) << numSum;
		outFile << "\n";
		specialCase = true;
	}
	
	if(d1 == 0 || d2 == 0)
	{
	outFile << setw(33) << n1  << setw(1) << "/" << setw(1) << d1 << setw(12) << "+" << setw(12) << n2 << setw(1) << "/" << setw(1) << d2 << setw(12) << "=" << " ERROR, CANNOT DIVIDE BY ZER0";
	outFile << "\n";
	specialCase = true;
	}
	
	if(specialCase == false)                                //found a duplicate printing error for whole numbers, added this loopn
	{
		if(numSum > denomSum || numSum * -1 > denomSum)
		{
			mixed = numSum / denomSum;
			if(numSum > 0)
			{
				numSum = numSum - (denomSum * mixed);
			}
		
			else
			{
				numSum = (numSum* -1) - (denomSum);
			}
		
			outFile << setw(33) << n1  << setw(1) << "/" << setw(1) << d1 << setw(12) << "+" << setw(12) << n2 << setw(1) << "/" << setw(1) << d2 << setw(12) << "=" << setw(12) << mixed << setw(3) << numSum << setw(1) << "/" << setw(1) << denomSum;
			outFile << "\n";
		
			specialCase = true;
		}
	
	}
	if(specialCase == false)
	{
		outFile << setw(33) << n1  << setw(1) << "/" << setw(1) << d1 << setw(12) << "+" << setw(12) << n2 << setw(1) << "/" << setw(1) << d2 << setw(12) << "=" << setw(12) << numSum << setw(1) << "/" << setw(1) << denomSum;
		outFile << "\n";
	}
}





