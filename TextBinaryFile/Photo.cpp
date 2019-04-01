#include "pch.h"
#include "Photo.h"


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
