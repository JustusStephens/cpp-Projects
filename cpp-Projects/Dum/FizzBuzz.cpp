#include <iostream>

using namespace std;

int main()
{
	bool fizzbuzz = false;
	
	for(int num=1; num<100; num++)
	{
		if(num % 3 == 0)
		{
			cout << "fizz";
			fizzbuzz = true;
		}
		
		if(num % 5 == 0)
		{
			cout << "buzz";
			fizzbuzz = true;
		}
		
		if(fizzbuzz == false)
		{
			cout << num;
		}
		
		cout << endl;
		fizzbuzz = false;
	}
}
