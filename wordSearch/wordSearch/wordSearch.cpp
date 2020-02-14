// The functions to allow program to read word search in text file.
//

#include "wordSearch.h"

//Reads a file and returns the text from the file as a string
//Parameters: file name as string
//Return: string
string readFile(string fileName)
{
	ifstream openFile(fileName);
	stringstream output;
	output << openFile.rdbuf();
	openFile.close();
	return output.str();
}

//Returns the first line of a string
//Parameters: text of file as a string
//Return: string
string getFirstLine(string textFile)
{
	string firstLine = "";
	istringstream textStream(textFile);
	getline(textStream, firstLine);
	return firstLine;
}

//Processes the text from a file into words. Delimited by ','
//Parameters: line of text as a string
//Return: vector of string
vector<string> getWords(string textFile)
{
	vector<string> words;
	stringstream  wordLine(getFirstLine(textFile));
	string temp;
	while (getline(wordLine, temp, ','))
	{
		words.push_back(temp);
	}
	return words;
}

//Converts text file of a word search without the words to a 2-d vector
//Parameters: String of the word search without the words so just the character grid
//Return: 2-d vector of characters
vector<vector<char> > getVectorCharGrid(string textFile)
{
	vector<vector<char> > returnVec;

	//Convert text file to sstring stream to use getline
	stringstream fileStream(textFile);
	string lineString;
	//Use string for able to use getLine to process a line of characters
	string tempString;
	int horCount = 0;

	//Loops through all the lines of text
	while(getline(fileStream, lineString))
	{
		stringstream lineStream(lineString);
		returnVec.push_back(vector<char>());

		//Loops through the line to get the characters
		while (getline(lineStream, tempString, ','))
		{
			//Push the character found onto the vector
			returnVec[horCount].push_back(tempString.at(0));
		}
		horCount++;
	}
	return returnVec;
}