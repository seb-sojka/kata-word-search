build: testWordSearch.o wordSearch.o
	g++ testWordSearch.o wordSearch.o -o testWordSearch

test: build
		./testWordSearch

wordSearch.o: wordSearch.cpp
	g++ -c wordSearch.cpp

testWordSearch.o: testWordSearch.cpp
		g++ -c testWordSearch.cpp

clean:
	rm *.o testWordSearch
