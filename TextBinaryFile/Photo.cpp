#include "pch.h"
#include "Photo.h"
#include <iterator> 
#include <iostream>
#include <list>
#include <string>


const int Photo::getId() const
{
	return id;
}

void Photo::showList()
{
	for (auto v :tagList)
		std::cout << v << " ";
	std::cout << std::endl;
}

void Photo::setVariable(int id, int height, int width)
{
	this->id = id;
	this->height = height;
	this->width = width;
}

Photo::Photo(int id, int height, int width)
{
	this->id = id;
	this->height = height;
	this->width = width;
}

Photo::Photo()
{

}

Photo::~Photo()
{
}
