// Used for testing of wordSearch.cpp
//
#include "wordSearch.h"
#include <algorithm>

const string testText =
R"(BONES,KHAN,KIRK,SCOTTY,SPOCK,SULU,UHURA
U,M,K,H,U,L,K,I,N,V,J,O,C,W,E
L,L,S,H,K,Z,Z,W,Z,C,G,J,U,Y,G
H,S,U,P,J,P,R,J,D,H,S,B,X,T,G
B,R,J,S,O,E,Q,E,T,I,K,K,G,L,E
A,Y,O,A,G,C,I,R,D,Q,H,R,T,C,D
S,C,O,T,T,Y,K,Z,R,E,P,P,X,P,F
B,L,Q,S,L,N,E,E,E,V,U,L,F,M,Z
O,K,R,I,K,A,M,M,R,M,F,B,A,P,P
N,U,I,I,Y,H,Q,M,E,M,Q,R,Y,F,S
E,Y,Z,Y,G,K,Q,J,P,C,Q,W,Y,A,K
S,J,F,Z,M,Q,I,B,D,B,E,M,K,W,D
T,G,L,B,H,C,B,E,C,H,T,O,Y,I,K
O,J,Y,E,U,L,N,C,C,L,Y,B,Z,U,H
W,Z,M,I,S,U,K,U,R,B,I,D,U,X,S
K,Y,L,B,Q,Q,P,M,D,F,C,K,E,A,B)";

const string testVectorText =
R"(U,M,K
H,U,L
K,I,N)";

const string findWord = "KIN";

//Expected corrindates left to right
const vector<vector<char> >expVectorCharLR = {
{'U','H','K'},
{'M','U','I'},
{'K','L','N'} };
const vector<vector<int>>expCorrLR = { {0, 2},{1, 2}, {2, 2} };
//Expected corrindates right to left
const vector<vector<char> >expVectorCharRL = {
{'U','H','N'},
{'M','U','I'},
{'K','L','K'} };
const vector<vector<int>>expCorrRL = { {2, 2},{1, 2}, {0, 2} };

const string testFile = "test.txt";
const string testFirstLine = "BONES,KHAN,KIRK,SCOTTY,SPOCK,SULU,UHURA";
const vector<string> testVectorWords = { "BONES", "KHAN", "KIRK", "SCOTTY", "SPOCK", "SULU", "UHURA" };

//Functions for testing
void testReadFile();
void testFindWordCorrLR();
void testFindWordCorrRL();
void testGetFirstLine();
void testProcessWords();
void testCharGridVector();

//Utility Functions
void stringCompareTest(string expected, string actual, string testName);
void intCompare(int exp, int auct, string testName);
int minCompare(int exp, int act, string testName);

//Runs the tests for wordSearch.cpp
int main()
{
	cout << "Tests for wordSearch.cpp\n";
	testReadFile();
	testGetFirstLine();
	testProcessWords();
	testCharGridVector();
	testFindWordCorrLR();
	testFindWordCorrRL();
}

//Tests function readFile from wordSearch.cpp
//Parameters: None
//Return: None
void testReadFile()
{
	stringCompareTest(testText, readFile(testFile), "Read File Test");
}

//An assert for compare strings
//Parameters: expected string, actual string, and the name of the test.
//Return: None
void stringCompareTest(string expected, string actual, string testName)
{
	cout << "\n" << testName << "\n";
	if ((actual.compare(expected)) == 0)
	{
		cout << "Success: String matches\n";
	}
	else
	{
		cout << "Failure: String doesn't match\n";
		cout << "String Expected:\n" << expected;
		cout << "\nString results:\n" << actual;
	}
}


//Test for parse the a string to return first line of a string and get the words.
//Parameters: None
//Return: None
void testGetFirstLine()
{
	stringCompareTest(testFirstLine, getFirstLine(testText), "Get First Line from String");
}

//Test for parse a string to return the words to find in a vector.
//Parameters: None
//Return: None
void testProcessWords()
{
	cout << "\nGet words from text and in a vector\n";
	vector<string> vectorWords = getWords(testText);
	
	//Get size of the vectors.
	int minSize = minCompare((int)testVectorWords.size(), (int)vectorWords.size(), "Word Vector Size");

	//Go through the strings in the vector and compare them
	for (int i = 0; i < minSize; i++)
	{
		string testName = "Vector String Test at index " + to_string(i);
		stringCompareTest(vectorWords.at(i), testVectorWords.at(i), testName);
	}
}

//Returns the min between 2 intgers and does compare between them
//Parameters: intergers for expected (exp) and acttual (act) along with string for test name
//Returns: Minimum between the 2 integers
int minCompare(int exp, int act, string testName)
{
	intCompare(exp, act, testName);
	return min(exp, act);
}

//Compares integers and prints out success or failure
//Parameters: 2 integers along with name of test as string
//Return: None
void intCompare(int exp, int act, string testName)
{
	cout << "\n" << testName << "\n";
	if (exp != act)
	{
		cout << "Failure: Values does not match\n";
		cout << "Expected Value: " << exp << "\n";
		cout << "Actual Value: " << act << "\n";
	}
	else
	{
		cout << "Success: Integers matches\n";
	}
}

//Prints the characters from a 2-d vector
//Parameters: 2-d vector of chracters
//Return: None
void printCharVector(vector<vector<char>>input)
{
	cout << "{ ";
	for (int i = 0; i < input.size(); i++)
	{
		cout << "{ ";
		cout << input[0][i];
		for (int j = 1; j < input[i].size(); j++)
		{
			cout << ", " << input[i][j];
		}
		cout << "},\n";
	}
	cout << "}";
}

//Test for change the grid of characters into a 2-D vector
void testCharGridVector()
{
	cout << "\nTest: Convert character grid to vector\n";
	vector<vector<char> > actVector = getVectorCharGrid(testVectorText);
	if (actVector == expVectorCharLR)
	{
		cout << "Success: Character grid vectors match\n";
	}
	else
	{
		cout << "Failure: Character grid don't vectors match\n";
		cout << "Expected vector\n";
		printCharVector(expVectorCharLR);
		cout << "Expected vector\n";
		printCharVector(actVector);
	}
}

//Prints the integers from a 2-d vector
//Parameters: 2-d vector of integers
//Return: None
void printIntVector(vector<vector<int>>input)
{
	cout << "{ ";
	for (int i = 0; i < input.size(); i++)
	{
		cout << "{ ";
		cout << input[i][0];
		for (int j = 1; j < input[i].size(); j++)
		{
			cout << ", " << to_string(input[i][j]);
		}
		cout << "},\n";
	}
	cout << "}";
}

//Test for find the coordinates of a word in a 2-d character vector in left to right order
void testFindWordCorrLR()
{
	cout << "\nTest: Find word in vector in left to right\n";
	vector<vector<int> > actCorr = findCorr(findWord, expVectorCharLR);
	if (expCorrLR == actCorr)
	{
		cout << "Success: Coordinates do match\n";
	}
	else
	{
		cout << "Failure: Coordinates do not match\n";
		cout << "Expected coordinates:\n";
		printIntVector(expCorrLR);
		cout << "Actual Vector:\n";
		printIntVector(actCorr);
	}
}

//Test for find the coordinates of a word in a 2-d character vector in right to left order
void testFindWordCorrRL()
{
	cout << "\nTest: Find word in vector in right to left\n";
	vector<vector<int> > actCorr = findCorr(findWord, expVectorCharRL);
	if (expCorrRL == actCorr)
	{
		cout << "Success: Coordinates do match\n";
	}
	else
	{
		cout << "Failure: Coordinates do not match\n";
		cout << "Expected coordinates:\n";
		printIntVector(expCorrRL);
		cout << "Actual Vector:\n";
		printIntVector(actCorr);
	}
}