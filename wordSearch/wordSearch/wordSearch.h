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
multimap<char, vector<int>> getCharGridMap(string textFile);