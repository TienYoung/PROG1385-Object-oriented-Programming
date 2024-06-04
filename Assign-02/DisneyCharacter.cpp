#include "DisneyCharacter.h"

DisneyCharacter::DisneyCharacter(const char* name, const char* creationDate, int numMovies, char whichPark)
	: name(""), creationDate("")
{
	EnsureNameAndDateValid(name, creationDate);
	SetNumMovies(numMovies);
	SetWhichPark(whichPark);
}

DisneyCharacter::DisneyCharacter(const char* name, const char* creationDate)
    : name(""), creationDate(""), numMovies(0), whichPark('N')
{
    EnsureNameAndDateValid(name, creationDate);
}

DisneyCharacter::~DisneyCharacter()
{
	printf("%s destroyed.\n", name);
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

bool DisneyCharacter::SetNumMovies(int num)
{

    bool valid = num >= 0;
    numMovies = valid ? num : 0;
    return valid;
}

bool DisneyCharacter::SetWhichPark(char park)
{
    switch (park)
    {
    case 'M':
        whichPark = 'M';
        return true;
    case 'S':
        whichPark = 'S';
        return true;
    case 'A':
        whichPark = 'A';
        return true;
    case 'E':
        whichPark = 'E';
        return true;
    case 'C':
        whichPark = 'C';
        return true;
    case 'N':
        whichPark = 'N';
        return true;
    default:
        whichPark = 'N';
        return false;
    }
}

void DisneyCharacter::ShowInfo(void)
{
    printf("# Disney character info #\n");
    printf("Name:\n\t%s\n", name);
    printf("Creation date:\n\t%s\n", creationDate);
    printf("Number of movies:\n\t%d\n", numMovies);
    printf("Which park:\n\t%c\n", whichPark);
    puts("");
}

bool DisneyCharacter::PlaceCharacter(char whichPark)
{
    return SetWhichPark(whichPark);
}

void DisneyCharacter::SameMovies(DisneyCharacter& anotherCharacter)
{
    SetNumMovies(anotherCharacter.numMovies);
}

void DisneyCharacter::EnsureNameAndDateValid(const char* name, const char* date)
{
    // Validate name
    size_t length = strlen(name) + 1;
    if (length > MAX_CHAR_LEN)
    {
        strncpy_s(this->name, MAX_CHAR_LEN, name, TRUNCATE_LEN);
        strcat_s(this->name, MAX_CHAR_LEN, "...");
    }
    else
    {
        strcpy_s(this->name, MAX_CHAR_LEN, name);
    }

    // Validate date
    bool isNegative = date[0] == '-';
    if (isNegative) date++;

    if (strlen(date) == kDateFormat)
    {
        int yyyy = 0, mm = 0, dd = 0;
        if (sscanf_s(date, "%4d-%2d-%2d", &yyyy, &mm, &dd) == 3)
        {
            if (isNegative) date--;

            strcpy_s(creationDate, MAX_CHAR_LEN, date);
        }
    }
}

