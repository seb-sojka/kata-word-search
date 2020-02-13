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

const multimap<char, vector<int>> expMap = {
	{'H', {1,0}},
	{'I', {2,1}},
	{'K', {0,2}},
	{'K', {2,0}},
	{'L', {1,2}},
	{'M', {0,1}},
	{'N', {2,2}},
	{'U', {0,0}},
	{'U', {1,1}}
};

const string testFile = "test.txt";
const string testFirstLine = "BONES,KHAN,KIRK,SCOTTY,SPOCK,SULU,UHURA";
const vector<string> testVectorWords = { "BONES", "KHAN", "KIRK", "SCOTTY", "SPOCK", "SULU", "UHURA" };

void testReadFile();
void stringCompareTest(string expected, string actual, string testName);
void testGetFirstLine();
void testProcessWords();
void testCharGridMap();
void intCompare(int exp, int auct, string testName);
int minCompare(int exp, int act, string testName);

//Runs the tests for wordSearch.cpp
int main()
{
	cout << "Tests for wordSearch.cpp\n";
	testReadFile();
	testGetFirstLine();
	testProcessWords();
	testCharGridMap();
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

//Prints the integers from a vector
//Parameters: a vector of integers
//Return: None
void printCharVector(vector<int>input)
{
	cout << "{ ";
	for (int i = 0; i < input.size(); i++)
	{
		cout << to_string(input[i]) << ", ";
	}
	cout << "}";
}

//Test for going from a string text of characters to a map
void testCharGridMap()
{
	multimap<char, vector<int>> actMap = getCharGridMap(testVectorText);

	cout << "\nGet string text from text and into a map\n";
	if (actMap == expMap)
	{
		cout << "Success: The maps match\n";
	}
	else
	{
		cout << "Failure: The maps do not match match\n";
		cout << "Expected Map\n";
		for (pair<char, vector<int>> elem : expMap)
		{
			cout << elem.first << " :: ";
			printCharVector(elem.second);
			cout << std::endl;
		}
		cout << "Actual Map\n";
		for (pair<char, vector<int>> elem : actMap)
		{
			cout << elem.first << " :: ";
			printCharVector(elem.second);
			cout << std::endl;
		}
	}
}