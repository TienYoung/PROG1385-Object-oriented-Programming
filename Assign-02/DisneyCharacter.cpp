#include "DisneyCharacter.h"

DisneyCharacter::DisneyCharacter(const char* name, const char* creationDate, int numMovies, char whichPark)
{
	SetName(name);
	SetCreationDate(creationDate);
	SetNumMovies(numMovies);
	SetWhichPark(whichPark);
}

DisneyCharacter::DisneyCharacter(const char* name, const char* creationDate)
{
	SetName(name);
	SetCreationDate(creationDate);
	SetNumMovies(0);
	SetWhichPark('N');
}

DisneyCharacter::~DisneyCharacter()
{

}

const char* DisneyCharacter::GetName() const
{
	return name;
}

const char* DisneyCharacter::GetCreationDate() const
{
	return creationDate;
}

int DisneyCharacter::GetNumMovies() const
{
	return numMovies;
}

char DisneyCharacter::GetWhichPark() const
{
	return whichPark;
}
