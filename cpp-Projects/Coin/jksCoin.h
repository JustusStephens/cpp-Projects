#ifndef JKSCOIN_H
#define JKSCOIN_H
#include <string>
#include <iostream>

class Coin
{
   private:
   	
      int Year;						// 0-2019
	  double FaceVal;				//.01,.5,.10,.25,.50,1.0
	  std::string Description;			//just repeat this back to user
	  int Quantity;					//how many they got
	  double MarketVal;				//marketVal 
	  double TotalVal;				//totalVal
      
   public:
   	
   	Coin()							//coin constructor
   	{
		Year; // = getYear();
		FaceVal; // = double getFaceVal() const;
		Description; // = std::string getDescription() const;
		Quantity; // =  int getQuantity() const;
		MarketVal; // = double getMarketVal() const;
		TotalVal; // =  double getTotalVal() const;
	}
   	
  	  void setYear(int);			//Accessors
      void setFaceVal(double);
      void setDescription(std::string);
      void setQuantity(int);
       
      int getYear() const;			//Mutators
      double getFaceVal() const;
      std::string getDescription() const;
      int getQuantity() const;
      double getMarketVal() const;	//dont need set, just return the calculations
      double getTotalVal() const;
      
	   
      
 //     ~Coin()					//destructor
 //     {
 //     	delete Year;
 //     	delete FaceVal;
 //     	delete Description;
 //     	delete Quantity;
 //     	delete MarketVal;
 //     	delete TotalVal;
//	  }
      
      

};
#endif
