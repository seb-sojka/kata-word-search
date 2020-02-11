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

const string testFile = "test.txt";
const string testFirstLine = "BONES,KHAN,KIRK,SCOTTY,SPOCK,SULU,UHURA";
const vector<string> testVectorWords = { "BONES", "KHAN", "KIRK", "SCOTTY", "SPOCK", "SULU", "UHURA" };

void testReadFile();
void stringCompareTest(string expected, string actual, string testName);
void testGetFirstLine();
void testProcessWords();


//Runs the tests for wordSearch.cpp
int main()
{
	cout << "Tests for wordSearch.cpp\n";
	testReadFile();
	testGetFirstLine();
	testProcessWords();
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
	int vectorSizeTest = (int)vectorWords.size();
	int vectorSizeExpected = (int)testVectorWords.size();
	if (vectorSizeTest != vectorSizeExpected)
	{
		cout << "Error: Size different in vector\n";
		cout << "Size Expected: " << vectorSizeExpected << "\n";
		cout << "Size Actual: " << vectorSizeTest << "\n";
	}
	else
	{
		cout << "Success: Size matches\n";
	}

	//Get the minimum size between the vectors to avoid memory errors. 
	int minSize = min(vectorSizeTest, vectorSizeExpected);

	for (int i = 0; i < minSize; i++)
	{
		string testName = "Vector String Test at index " + to_string(i);
		stringCompareTest(vectorWords.at(i), testVectorWords.at(i), testName);
	}
}