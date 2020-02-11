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