#pragma once
#include <iostream>
#include <list>

class Photo
{
private:
	int id;
	int height;
	int width;
public:
	void setVariable(int, int, int);
	std::list<std::string> tagList;
	Photo(int,int,int);
	Photo();
	~Photo();
};

