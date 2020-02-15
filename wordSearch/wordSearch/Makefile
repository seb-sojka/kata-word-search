# Specify compiler
CC=cl.exe

# Specify linker
LINK=link.exe

build: wordSearch.o testWordSearch.o
	$(LINK) /OUT:testWordSearch.exe wordSearch.obj testWordSearch.obj

test: build
	testWordSearch.exe

wordSearch.o: wordSearch.cpp
	$(CC) /c wordSearch.cpp

testWordSearch.o: testWordSearch.cpp
	$(CC) /c testWordSearch.cpp

clean: 
	del *.obj testWordSearch.exe