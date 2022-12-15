//Justus Stephens
//Assignement 3 cps 161
//2/6/19

#include <iostream>
#include <cstring>
#include <cmath>
#include <sstream>       //Only way i could get my doubles into my string
using namespace std;

//Prototypes

void getID(int &);
void getCode(int &);
void calcPay (double &, double &, double &, double &, int &);
void getRerun (bool &);

int main()
{
	string outputFinal;    //To store all output in one place
	int id;           //The employee's id
	int code;         //The employee's salary code
	double gross;     //weekly pay
	double tax;       //Tax amount
	double deduct;    //Deduction amount
	double net;       //Take home pay
	bool run;	      //Run again boolean
	
	do
	{
		getID(id);
		getCode(code);
		calcPay(gross, tax, deduct, net, code);
		getRerun(run);
		
		//Running my output in my main to accumulate the data for every employee the user enters into 1 string (outputFinal)
		
		std :: ostringstream out1;                            //How i got my doubles to add to my string
		out1 << id;												//id
		std:: string output1 = "Employee #" + out1.str();
		output1 = output1 +"\n";

		std :: ostringstream out2;								//gross
		out2 << round(gross*100) / 100.00;
		std:: string output2 = "$" + out2.str();
		output2 = output2 +" is your gross \n";

		std :: ostringstream out3;								//tax
		out3 << round(tax*100) / 100.00;
		std:: string output3 = "-$" + out3.str();
		output3 = output3 +" is your tax amount \n";

		std :: ostringstream out4;								//deduction amount
		out4 << round(deduct*100) / 100.00;
		std:: string output4 = "-$" + out4.str();
		output4 = output4 +" is your deduction \n";

		std :: ostringstream out5;								//net pay
		out5 << round(net*100) / 100.00;
		std:: string output5 = "=$" + out5.str();
		output5 = output5 +" is your net pay \n";

		outputFinal += "\n" + output1 + output2 + output3 + output4 + output5;	
		
		
	} while (run == true);
	
	cout << outputFinal;
	
	return 0;
	
}
	
	//Function get id///////////////////////////////////////////////////////////
	
	void getID(int &id)
	{
		cout << "Please enter the employee's id." << endl;
		cin >> id;
	}
	
	//Function get salary code////////////////////////////////////////////////
	
	void getCode(int &code)
	{
		cout << "Please enter the employee's salary code." << endl;
		cin >> code;
	}
	
	//function calc pay /////////////////////////////////////////////////////
	
	void calcPay(double &gross, double &tax, double &deduct, double &net, int &code)
	{
		
		switch(code)
		{
			case 1:
				 gross = 60000.00 / 52.00;
				 tax = 0.19 * gross;
				 deduct = 27.85;
				 net = gross - tax - deduct;
				 break;
				 
			case 2:
				double hours;
				cout << "How many hours did the employee work? \n";
				cin >> hours;
				if(hours > 40)
				{
					gross = (hours - 40) * (15.85 * 1.5);                    //time and a half
				}  
				gross += hours * 15.85;
				tax = 0.19 * gross;
				deduct = 27.85;
				net = gross - tax - deduct;
				break;
				
			case 3:
				double sales;
				cout << "How much did the employee sell in $? \n";
				cin >> sales;
				gross = 350 + (sales * .057);
				tax = 0.19 * gross;
				deduct = 27.85;
				net = gross - tax - deduct;
				break;
			case 4:
				double prodAmount;
				cout << "How many widgets did the employee produce? \n";
				cin >> prodAmount;
				gross = prodAmount * 12.30;
				tax = 0.19 * gross;
				deduct = 0;
				net = gross - tax - deduct;
				break;
			case 5:
				 gross = 360000.00 / 52.00;
				 tax = 0.19 * gross;
				 deduct = 27.85;
				 net = gross - tax - deduct;
				 break;
		}
	}
	
	//Function get run again val////////////////////////////////////////////
	void getRerun(bool &run)
	{
		int input;
		cout << " \n If you are done entering data enter 0 \n";
		cout << "If you wish to enter more data enter 1 \n";
		cin >> input;
		
		if(input == 0)
			run = false;
		else
			run = true;
	}

