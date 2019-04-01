#pragma once
#include <list>
#include "Photo.h"
#include <iostream>
#include <fstream>

class FileManager
{
private:
	const static int tabSize = 100000;
	std::ifstream input;
	const char* fileName;
	Photo* photoArray = new Photo[tabSize];
	int findTag(const char*);
public:
	void addPhoto(int, int, int, std::string[],int);
	const char getFilename() const;
	void loadFile();
	FileManager(const char*);
	~FileManager();
};

