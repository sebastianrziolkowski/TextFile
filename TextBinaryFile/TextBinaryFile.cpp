#include "pch.h"
#include <iostream>
#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	const char* fileName = "images.txt";
	FileManager fileManager(fileName);
	fileManager.loadFile();
	
	return 0;

}