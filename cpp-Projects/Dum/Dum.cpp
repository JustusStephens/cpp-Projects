#include <iostream>

using namespace std;

int main() {
	
	for(int wave=0; wave<20; wave++)
	{
			for(int count =1; count<50; count++)
		{
			for(int count2=0; count2<count; count2++)
				cout << "*";
			cout << "\n";
		}
		
		for(int c=50; c>0; c--)
		{
			for(int c2=c; c2>0; c2--)
				cout << "*";
			cout << "\n";
		}
	}

}
