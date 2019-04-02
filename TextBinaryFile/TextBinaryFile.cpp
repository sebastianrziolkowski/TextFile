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
	//fileManager.showTags();


	const char* tag1 = "cats";
	const char* tag2 = "work";
	const char* tag3 = "vacation";
	
	std::cout << tag1 << ": " << fileManager.findTag(tag1) << std::endl;
	std::cout << tag2 << ": " << fileManager.findTag(tag2) << std::endl;
	std::cout << tag3 << ": " << fileManager.findTag(tag3) << std::endl;

	static const int id = 99998;
	static const int height = 480;
	static const int width = 640;
	std::string tagArray[] = {"sunrises","kittens","travel"};

	fileManager.addPhoto(id, height, width, tagArray, sizeof(tagArray) / sizeof(tagArray[0]));

	
	return 0;

}