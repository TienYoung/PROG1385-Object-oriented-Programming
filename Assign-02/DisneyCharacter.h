#pragma once

#include <cstring>

#define MAX_CHARS 50

class DisneyCharacter
{
public:
	DisneyCharacter(const char* name, const char* createDate, int numMovies, char whichPark);
	~DisneyCharacter();

	void SetName(const char* name)
	{
		strcpy_s(this->name, MAX_CHARS, name);
	}
	void SetCreationDate(const char* date);
	void SetNumMovies(int num);
	void SetWhichPark(char park);

private:
	char name[50];
	char creationDate[50];
	int numMovies;
	char whichPark;
};

