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

	//Loops through all the lines of text
	while(getline(fileStream, lineString))
	{
		stringstream lineStream(lineString);
		int vertCount = 0;
		//Loops through the line to get the characters
		while (getline(lineStream, tempString, ','))
		{
			//Adds new vector if needed
			if (vertCount >= returnVec.size())
			{
				returnVec.push_back(vector<char>());
			}
			//Push the character found onto the vector
			returnVec[vertCount].push_back(tempString.at(0));
			vertCount++;
		}
	}
	return returnVec;
}

//Sees if word is at current location in the inputed directions
//Parameters: word as string, 2-d vector of characters, starting coordinates as vector of integer, direction to next character as vector of integers, size of vector as integer
//Return: true if word is found, false if not
bool directionSearch(string word, vector < vector<char> >  grid, vector<int> starting, vector<int> direction, int vectorSize)
{
	//Starting location
	int xCorr = starting[0];
	int yCorr = starting[1];
	
	int charCount = 0;

	bool matchWord = true;
	//Loops thourgh the direction desired as long within the boundries of the grid and 
	while (xCorr >= 0 && yCorr >= 0 && xCorr < vectorSize && yCorr < vectorSize && charCount != word.length() && matchWord)
	{
		if (word.at(charCount) == grid[xCorr][yCorr])
		{
			charCount++;
			xCorr += direction[0];
			yCorr += direction[1];
		}
		else
		{
			matchWord = false;
		}
	}
	return (charCount == word.length());
}

//Sets up 2-d vector for coordinates of found word
//Parameters: starting coordinates as vector of integer, direction to next character as vector of integers, length of word as integer
//Return: vector
vector<vector<int> > setCoor(vector<int> starting, int length, vector<int> direction)
{
	vector<vector<int> > retVector;
	for (int i = 0; i < length; i++)
	{
		retVector.push_back({ starting[0] + i * direction[0], starting[1] + i * direction[1] });
	}

	return retVector;
}

//Finds coordinates to spell out a word 
//Parameters: word as string, 2-d vector of characters
//Return: 2-d vector of integers 
vector<vector<int> > findCorr(string word, vector < vector<char> >  grid)
{
	int directionIndex = 0;
	vector<int> startingCoor;
	vector<vector<int> > possibleDirections =
	{
		{1,0},//Left
		{-1,0},//Right
		{0,1},//Down
		{0,-1},//Up
		{1, 1},//left to right down
		{1, -1}//left to right up
	};
	
	//Size of lines
	int limit = (int)grid.size();

	bool foundWordFlag = 0;

	//Go through the vertical lines of vector
	for (int i = 0; i < limit; i++)
	{
		//Count for which character in the word we are looking for
		int charCount = 0;
		//Go each character in line
		for (int j = 0; j < limit; j++)
		{
			for (int k = 0; k < possibleDirections.size(); k++)
			{
				startingCoor = { j, i };
				directionIndex = k;
				foundWordFlag = directionSearch(word, grid, startingCoor, possibleDirections[directionIndex], limit);
				if (foundWordFlag)
				{
					break;
				}
			}
			if (foundWordFlag)
			{
				break;
			}
		}
		if (foundWordFlag)
		{
			break;
		}
	}
	return setCoor(startingCoor, (int)word.length(), possibleDirections[directionIndex]);
}