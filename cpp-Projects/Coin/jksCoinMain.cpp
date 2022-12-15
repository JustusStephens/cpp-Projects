
#include "jksCoin.h"
#include <iostream>
#include <cwchar> 	//for font
#include <windows.h>//for font 
#include <string>
#include <iostream>

using namespace std;

//Main/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
		//makes my output pretty
		
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // width of character
	cfi.dwFontSize.Y = 20;                  // height
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	system ("color 70");
	
	
	
	
	 Coin collectionArray[3];					//array of objects
	
	
	for(int count=0; count <3; count++)
	{
		
  		 Coin cn;     			//instance of coin class
   		 int cnYear;  			//local vars
  		 double cnFaceVal; 		
  		 string cnDescription;
  		 int cnQuantity;
  		 double cnMarketVal;
  		 double cnTotalVal;


   
   		 cn.setYear(cnYear);
   		 cn.setFaceVal(cnFaceVal);
   		 cn.setDescription(cnDescription);
   		 cn.setQuantity(cnQuantity);
   		 
   		 
   		 
   		 cnYear = cn.getYear();
   		 cnFaceVal = cn.getFaceVal();
   		 cnDescription = cn.getDescription();
   		 cnQuantity = cn.getQuantity();
   		 cnMarketVal = cn.getMarketVal();			//just get the calc for these two
   		 cnTotalVal = cn.getTotalVal();

  		// Output.
   
   		cout << "\n\n					The #" << count+1 << " coin you entered: \n";
   		cout << "					Year: " << cnYear << "\n";
   		cout << "					Face Value: " << cnFaceVal << "\n";
   		cout << "					Description: " << cnDescription << "\n";
   		cout << "					Quantity: " << cnQuantity << "\n";
   		cout << "					Market Value: $" << cnMarketVal << "\n";
   		cout << "					Total Value: $" << cnTotalVal << "\n";
   		cout << "\n\n\n\n\n";
   		
  	}
}
