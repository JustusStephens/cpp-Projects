#include "jksCoin.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iostream>


//assigns value to year/////////////////////////////////////////////////////////////////////

void Coin::setYear(int y)
{
	y = -1;
	while(y<0)
	{
		std::cout << "					What year is your coin from? \n";
		std::cin >> y;
		if(y<0)
		{
			std::cout << "\n 				Sorry, no negative years allowed.\n ";
			std::cout << "					Please enter a year from 0-present\n";
		}
	}
   Year = y;
}

//assigns value to face val/////////////////////////////////////////////////////////////////////

void Coin::setFaceVal(double fv)
{
	fv = -1;
	while(fv<=0)
	{
		std::cout << "					what is the face value of your coin? \n";
		std::cin >> fv;
		
		if(fv <= 0)
		{
			std::cout << "\n 			Sorry, no negative values allowed.\n ";
			std::cout << "				Please enter a value greater than 0\n";
		}
	}
   FaceVal = fv;
}

//assigns value to description/////////////////////////////////////////////////////////////////

void Coin::setDescription(std::string d)
{
	std::cout << "					Please enter a 1 word description of your coin: \n";
	std::cin >> d;
	Description = d;
}

//assigns value to quantity///////////////////////////////////////////////////////////////////

void Coin::setQuantity(int q)
{
	q=-1;
	
	while(q<=0)
	{
			std::cout << "					How many of those coins do you have?\n";
			std::cin >> q;      
			//system("PAUSE");
			if(q<=0)
			{
				std::cout << "			Please enter a positive quantity \n";
			}
	}
	std::cout << "in set q eaquals: " << q;
	Quantity = q;
	
}

//returns value of year////////////////////////////////////////////////////////////////////

int Coin::getYear() const
{
   return Year;
}

//returns value of Face//////////////////////////////////////////////////////////////////

double Coin::getFaceVal() const
{
   return FaceVal;
}

//Returns description/////////////////////////////////////////////////////////////////////

std::string Coin::getDescription() const
{
	return Description;
}

//Returns Quantity///////////////////////////////////////////////////////////////////////

int Coin::getQuantity() const
{
	return Quantity;
}

//returns Market Val////////////////////////////////////////////////////////////////////////

double Coin::getMarketVal() const
{
   return FaceVal*Quantity;
}

//returns TotalVal

double Coin::getTotalVal() const
{
   return Quantity*(FaceVal+((2019-Year)*.001));   //Percentage of age plus faceVal times Quantity
}
