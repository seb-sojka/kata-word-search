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