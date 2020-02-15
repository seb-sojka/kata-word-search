#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

string readFile(string fileName);
string getFirstLine(string textFile);
vector<string> getWords(string textFile);
vector<vector<char> > getVectorCharGrid(string textFile);
vector<vector<int> > findCorr(string word, vector < vector<char> >  grid);
map < string, vector<vector<int > >> findAllWords(vector<string> words, vector < vector<char> >  grid);