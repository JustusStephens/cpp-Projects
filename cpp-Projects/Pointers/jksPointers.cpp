#include <iostream>
#include <string>
using namespace std;

void input(char [], char[]);
char *searcher(char [], char []);

int main()
{
	bool run = true;
	
	while(run == true)
	{
		char *psource;			//my pointer to source
		char *pset;				//pointer to set
		char source [] = "";	//char array of source
		char set [] = "";		//char array of set
		char *answer;
		
		input(source,set);		//call input function and fill char arrays
		
		psource = &source[0];
		pset = &set[0];
		
		answer=searcher(source,set);
		
	//	cout << answer;
		
		run = false;
		
	}
}

void input(char source[], char set[])
{
	string line;
	string line2;
	
	cout << "Please enter your source string. \n";
	getline(cin,line);
	
	cout << "\n" << "source in the input function is: ";
	
	for(int x=0; x<line.length(); x++)
	{
		source[x] = line[x];
		cout << source[x];
	}
	
	cout << "\n\n\n";
	
	cout << "Please enter your set string. \n";
	getline(cin,line2);
	
	cout << "\nset in the input function is: ";

	for(int x=0; x<line2.length(); x++)
	{
		set[x] = line2[x];
		cout << set[x];
	}
	

}

char *searcher(char* source, char* set)
{
	char *answer;
	answer = source;
	bool found = false;
	
	while(source != NULL && found == false)
	{
		cout << "\n\n" << source << " source string in searcher       " << set << " set string in searcher" << endl;
		found = true;
	}
	return answer;
}
