#include "pch.h"
#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <string>


FileManager::FileManager(const char* fileName)
{
	this->fileName = fileName;

	input.open(fileName);

	if (!input.good())
	{
		throw "File open error.";
	}
}


FileManager::~FileManager()
{
	input.close();
}


const char FileManager::getFilename() const
{
	return *this->fileName;
}


int FileManager::findTag(const char *tag)
{
	int counter = 0;
	for (int i = 0; i < this->tabSize; i++)
	{
		if (std::find(photoArray[i].tagList.begin, photoArray[i].tagList.end, tag) == tag)
			counter++;
	}
	return counter;
}


void FileManager::addPhoto(int id, int height, int width, std::string tagsArray[], int tagArraySize)
{
	photoArray[id] = Photo(id, height, width);
	photoArray[id].tagList.clear();
	for (int i = 0; i < tagArraySize; i++)
	{
		photoArray[id].tagList.push_front(tagsArray[i]);
	}
}

void FileManager::loadFile()
{
	std::string pom;
	std::string temp;
	int id;
	int height;
	int width;

	getline(input, pom);

	while (!input.eof())
	{
		input >> pom;
		int i = 0;
		while (pom.at(i) != ',')
		{
			temp += pom.at(i);
			i++;
		}
		id = std::atoi(temp.c_str());
		temp = "";
		i++;

		while (pom.at(i) != ',')
		{
			temp += pom.at(i);
			i++;
		}
		height = std::atoi(temp.c_str());
		temp = "";
		i++;
		while (pom.at(i) != ',')
		{
			temp += pom.at(i);
			i++;
		}
		width = std::atoi(temp.c_str());
		temp = "";
		i++;

		photoArray[id].setVariable(id, height, width);

		while (i < (int)pom.length())
		{
			while (i < (int)pom.length() && pom.at(i) != ',')
			{
				temp += pom.at(i);
				i++;
			}
			photoArray[id].tagList.push_front(temp);
			temp = "";
			i++;
		}


	}
}