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
		for (auto v : this->photoArray[i].tagList)
			if (v == tag)
			{
				counter++;
			}
			
	}
	return counter;
}


void FileManager::showTags()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Tags for id: " << photoArray[i].getId() << " ";
		photoArray[i].showList();
	}
}

void FileManager::addPhoto(int id, int height, int width, std::string tagsArray[], int arrayStringSize)
{
	photoArray[id] = Photo(id, height, width);
	photoArray[id].tagList.clear();
	std::string tagString;
	for (int i = 0; i < arrayStringSize; i++)
	{
		photoArray[id].tagList.push_back(tagsArray[i]);
		tagString += "," + tagsArray[i];
	}
	std::string temp = "\n" + std::to_string(id) + "," + std::to_string(height) + "," + std::to_string(width) + tagString;
	
	input.close();

	output.open(fileName, std::ios_base::app);
	if (!output.good())
	{
		throw "Open output file erro.";
	}

	output << temp;

	output.close();
	input.open(fileName);
	if (!input.good())
	{
		throw "Reopen input file erro.";
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
			photoArray[id].tagList.push_back(temp);
			temp = "";
			i++;
		}


	}
}