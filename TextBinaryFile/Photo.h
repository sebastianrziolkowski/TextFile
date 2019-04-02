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
	const int getId() const;
	std::list<std::string> tagList;
	void showList();
	void setVariable(int, int, int);
	Photo(int,int,int);
	Photo();
	~Photo();
};

