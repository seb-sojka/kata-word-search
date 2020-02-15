Word Search Testing
================
Hello
This program tests of functions related to word search program. The program can read a text file format and return words found and coordinates of their characters.

Note: Input and output section is taken from instructions given for this exercise.

## Build and Run ##
### Linux ###
First, update the gcc and g++ as to avoid errors in compiling, building, and running the program. They can be update or installed by the following commands in terminal.
```
sudo apt-get install gcc
sudo apt-get install g++
```
In order to run test, open terminal with Makefile, *\kata-word-search\wordSearch\wordSearch.

To compile and build, enter `make` into the terminal. This will compile and build the test program, testWordSearch. testWordSearch can be run with type its name into terminal.

To compile, build, and run test program, enter `make test`. This will compile, build, and run the test program.

## Input ##

The first line of the text file will consist of the list of words to be found.  The following lines will consist of a list of single characters, A-Z. All lines in the file except the first will have the same length, and the number of rows will match the number of characters in a line.  This input represents the square grid of the word search.

The grid will always be square, and all words in the list will always be present in the grid. Words may be located horizontally, vertically, diagonally, and both forwards and backwards.  Words will never "wrap" around the edges of the grid.

The following is an example of the format of the input file:

<pre>
BONES,KHAN,KIRK,SCOTTY,SPOCK,SULU,UHURA
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
K,Y,L,B,Q,Q,P,M,D,F,C,K,E,A,B
</pre>

## Output ##
The output of the program is the location of each word found, each on a separate line.  The location will be represented as a series of x,y coordinates, where both x and y start at zero at the top-left of the grid.  From this position both x and y will increase, i.e. they will never be negative.

Given the example input above, the following output would be expected:

<pre>
BONES: (0,6),(0,7),(0,8),(0,9),(0,10)
KHAN: (5,9),(5,8),(5,7),(5,6)
KIRK: (4,7),(3,7),(2,7),(1,7)
SCOTTY: (0,5),(1,5),(2,5),(3,5),(4,5),(5,5)
SPOCK: (2,1),(3,2),(4,3),(5,4),(6,5)
SULU: (3,3),(2,2),(1,1),(0,0)
UHURA: (4,0),(3,1),(2,2),(1,3),(0,4)
</pre>
