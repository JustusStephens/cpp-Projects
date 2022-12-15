#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

string userInput();
int numWords(string);
void stringToVector(string, int, vector<string> &);
void pigVect(vector<string>, int, vector<string> &);
void charToEnd(int, string, vector<string> &);
string suffix(int, string);
string punctuation(string);
string lower(string);
void printVector(vector<string>);
void stringToVectorReverse(string, int, vector<string> &);
void printVectorReverse(vector<string>);
string upper(string);

int main()
{
	string input;
	int numWord;
	vector<string> pigSentence;
	vector<string> engSentence;
	int count = 40;
	
	input = userInput();							//gets the sentence
	input = lower(input);
	numWord = numWords(input);						//numwords
				
	vector<string> reverse;							//reverse portion
	string input2 = upper(input);
	stringToVectorReverse(input2, numWord, reverse);    //puts my string into a vector
	printVectorReverse(reverse);

	stringToVector(input, numWord, engSentence);    //puts my string into a vector
	pigVect(engSentence, count, pigSentence);		//puts pig latin words into the pig latin sentence vector
	printVector(pigSentence);						//prints vector with range based for loop
	
	
}

//Get the sentence////////////////////////////////////////////////////////////////////////////

string userInput()
{
    string input;
    cout << "Enter a sentence you would like to see reversed and in pig latin: \n";
    getline(cin, input);
    
    return input;
}

//Upper caseing all words////////////////////////////////////////////////////////////////////////////////////////////////

string lower(string input)
{
	for(int x = 0; x < input.length(); x++)
    {
       	 if(isalpha(input[x]))
            input[x] = tolower(input[x]);
    }
    return input;
}

//Count the number of words///////////////////////////////////////////////////////////

int numWords(string sentence)
{
    int numWord = 0;
    
    for(int x = 0; x < sentence.size(); x ++)
    {
        if(isspace(sentence[x]) && (isalpha(sentence[x - 1]) || ispunct(sentence[x - 1])))       //if there is a letter or punc behind a space, then add 1 to word count
            numWord++;
        else if(x == sentence.size()-1 && !isspace(sentence[x]))								//accounting for last word without space at the end
            numWord ++;
    }
    return numWord;
}

//putting string into a vector////////////////////////////////////////////////////////////////////

void stringToVector(string input, int numWords, vector<string> &engSentence)
{
    string oneWord;
    stringstream ss(input);
    
    for(int x = 0; x < numWords; x++)			//puts a word into my english vector 1 at a time
    {
        ss >> oneWord;							
        engSentence.push_back(oneWord);
    }
}

//fixing up the pig latin vector////////////////////////////////////////////////////////////////////////////////////////////

void pigVect(vector<string> engSentence, int count, vector<string> &pigSentence)
{
    for(int x = 0; x < engSentence.size(); x ++)						
    {
        charToEnd((int)engSentence.at(x).length(), engSentence.at(x), pigSentence);		//
        pigSentence.at(x) = suffix(count, pigSentence.at(x));
    }
}

//Swapping my first char(s) to the end///////////////////////////////////////////////////////////////////////////////////

void charToEnd(int size, string engSentence, vector<string> &pigSentence)
{
	bool vowel = false;
	int count = 0;
	while(vowel==false)
	{
		if(engSentence[count] == 'a' || 'e' || 'i' || 'o' || 'u' || 'y')
			vowel = true;
		else
			count++;
	}
    char array = engSentence[count];
    string spot = "";
    for(int x = 0; x < size; x++)
    {
        if(x < size - 1 && size != 1) 
            spot += engSentence[x + 1];
        else if(size==1)
        	spot += array;
        else
            spot += array;
    }
    pigSentence.push_back(spot);
}

//Adding the suffix//////////////////////////////////////////////////////////////////////////////////////////////////////

string suffix(int size, string word)
{
    string pigWord;
    char in[size];
    
    fill_n(in, size, 0);
    
   		char pig[] = "ay";
    	for(int x = 0; x < word.length(); x++)
    		in[x] = word[x];
    	pigWord = strncat(in, pig, 2);
	
    pigWord = punctuation(pigWord);
    return pigWord;
}

//Fixing punc////////////////////////////////////////////////////////////////////////////////////////////////////////////

string punctuation(string pigWord)
{
    string output = pigWord;
    bool punct_found = false;
    char temp;
    for(int i = 0; i < output.length(); i++)
    {
        if(ispunct(output[i]))
        {
            temp = output[i];
            punct_found = true;
        }
        if(punct_found && i < output.length() - 1)
            output[i] = output[i + 1];
        else if(punct_found && i == output.length() - 1)
            output[i] = temp;
    }
    return output;
}


//output/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void printVector(vector<string> input)
{
    for(string x : input)					//x is one word, print till no more words
        cout << x << " ";
    cout << endl;
}

void stringToVectorReverse(string input, int numWords, vector<string> &reverse)
{
    string oneWord;
    stringstream ss(input);
    
    for(int x = numWords-1; x >= 0; x--)			//puts a word into my english vector 1 at a time
    {
        ss >> oneWord;							
        reverse.push_back(oneWord);
    }
}

void printVectorReverse(vector<string> reverse)
{
	cout << "\n";
     for(int x = reverse.size() - 1; x>=0; x--)
     {
     	cout << reverse[x] << " ";
	 }
	 cout << "\n\n";
}

string upper(string input)
{
	for(int x = 0; x < input.length(); x++)
    {
       	 if(isalpha(input[x]))
            input[x] = toupper(input[x]);
    }
    return input;
}
