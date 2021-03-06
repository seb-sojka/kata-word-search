// The functions to allow program to read word search in text file.
//

#include "wordSearch.h"

//Finds all the words in a vector in 2-d character grid
//Parameters: words to find as vector of string, text grid as 2-d vector
//Return: map with string as key and corrdinates as 2-d vector of integers as value
map < string, vector<vector<int > >> findAllWords(vector<string> words, vector < vector<char> >  grid)
{
	map < string, vector<vector<int > >> retMap;

	for (int i = (int)words.size() - 1; i >= 0; i--)
	{
		retMap[words[i]] = findCorr(words[i], grid);
	}

	return retMap;
}

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
		{1, 0},//Left to right
		{-1, 0},//Right to left
		{0, 1},//Up to down
		{0, -1},//Down to up
		{1, 1},//left to right down
		{1, -1},//left to right up
		{-1, -1},//right to left up
		{-1, 1}//Right to left down
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

//Performs a word search on a text file. Opens file, read and processes it, and returns map with string of words to be found and 2-d vector of their character's coordinates
//Parameters: file name as string
//Return: map with string as key and corrdinates as 2-d vector of integers as value
map < string, vector<vector<int > >> wordSearch(string fileName)
{
	string textFile = readFile(fileName);
	vector<string> words = getWords(textFile);

	//removes words from string file so it is only the character grid
	textFile.erase(0, textFile.find("\n") + 1);

	vector<vector<char> >textGrid = getVectorCharGrid(textFile);
	return findAllWords(words, textGrid);
}

//Prints the integers from a 2-d vector
//Parameters: 2-d vector of integers
//Return: None
static void printIntVector(vector<vector<int>>input)
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
		cout << "}, ";
	}
	cout << "}";
}

//Prints out a map with values as string and 2-d vector as values
//Parameters: Map with values as string and 2-d vector as values
//Return: none
void printMap(map < string, vector<vector<int > >> map)
{
	for (pair< string, vector<vector<int>>> elem : map)
	{
		cout << elem.first << " : ";
		printIntVector(elem.second);
		cout << "\n";
	}
}