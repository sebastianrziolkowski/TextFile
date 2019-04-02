#pragma once
#include <list>
#include "Photo.h"
#include <iostream>
#include <fstream>

class FileManager
{
private:
	const static int tabSize = 110000;
	std::ifstream input;
	std::ofstream output;
	const char* fileName;
	Photo* photoArray = new Photo[tabSize];
public:
	int findTag(const char*);
	void showTags();
	void addPhoto(int, int, int, std::string[], int);
	const char getFilename() const;
	void loadFile();
	FileManager(const char*);
	~FileManager();
};

