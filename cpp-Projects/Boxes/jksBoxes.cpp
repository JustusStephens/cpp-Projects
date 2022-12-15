//Assignment 4
//Justus Stephens
//February 14, 2019

#include <iostream>
#include <fstream>          //Reading and writing files
#include <iomanip>          //Decimal precision
#include <string>
#include <sstream>          //So i can split my strings into doubles


using namespace std;

void outputFile(double &, double &, double &, double &, double &, bool &);

ofstream outFile;

int main()
{
	int number;
	string line;
	ifstream inFile ("P4Boxes(1).txt");
	

	outFile.open("Assignment4Answers.txt");
	outFile << "					Justus Stephens Assigment 4 Answers			\n \n";
	outFile <<"			Box					Jar		   		  Will it fit? \n";
	outFile<<"  	Length		Width		Height		Diameter   Height		    	  Yes or No  \n";
	
	if(inFile.is_open())
	{
		while( getline (inFile,line) )
		{
			
			bool fit = false;          //False until proven true
			
			stringstream ss(line);
			double bl; ss >> bl;    //Box length
			double bw; ss >> bw;    //Box width
			double bh; ss >> bh;    //Box height
			double jd; ss >> jd;    //Jar diameter
			double jh; ss >> jh;    //Jar height
			
			//Begin 3 sets of nested loops to test fit////////////////////////////////////////////
			
			//1st tests the length of jar with length of box
			
			if(bl - .25 >= jd)
			{
				if(bw - .25 >= jd)
				{
					if(bh-.25 >= jh)
					{
						fit = true;
					}
				}
			}
			
			//2nd tests length of jar with width of box
			
			if(fit == false)
			{
			  if(bh - .25 >=jd)
				{
					if(bl - .25 >= jd)
					{
						if(bw-.25 >= jh)
						{
							fit = true;
						}
					}
				}
			}
			//3rd tests length of jar with length of box
			
			if(fit == false)
			{
				if(bw - .25 >= jd)
				{
					if(bh - .25 >= jd)
					{
						if(bl - .25 >= jh)
						{
							fit = true;
						}
					}
				}
			}
			//At this point if fit==true then the jar will fit
			
			outputFile(bl, bw, bh, jd, jh, fit);
			
		}
		
	}
	
	else   //Unable to open file, you go here
		cout << "Unable to open file: P4Boxes(1).txt";
		
		outFile.close();
		
		cout << "Please see file for results.";
		
		return 0;	
}

void outputFile(double &bl, double &bw, double &bh, double &jd, double &jh, bool &fit)
{


	if(fit == true)
	{
	outFile << setw(12) << bl << setw(15) << bw << setw(18) << bh << setw(15) << jd << setw(11) << jh << setw(35) << "Yes \n";
	}
	
	else
	{
	outFile << setw(12) << bl << setw(15) << bw << setw(18) << bh << setw(15) << jd << setw(11) << jh << setw(35) << "No \n";
	}

}
