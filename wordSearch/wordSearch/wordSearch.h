#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

string readFile(string fileName);
string getFirstLine(string textFile);
vector<string> getWords(string textFile);