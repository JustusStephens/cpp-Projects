#include <iostream>

using namespace std;

struct MyNumber
{
    MyNumber(int value) : value(value){} 

    int Value()				//need to access the value
    {
        return value;
    }

private:
    const int value;
};	
	
int main()
{
	MyNumber number = 7;
	cout << number.Value();
	number = 3;
	cout << number.Value();
}
