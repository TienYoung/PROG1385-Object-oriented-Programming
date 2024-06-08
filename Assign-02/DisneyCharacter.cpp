#include "DisneyCharacter.h"

bool validateName(char* output, const char* name)
{
    size_t length = strlen(name) + 1;
    if (length > MAX_CHAR_LEN)
    {
        strncpy_s(output, MAX_CHAR_LEN, name, TRUNCATE_LEN - 1);
        strcat_s(output, MAX_CHAR_LEN, " ...");
        return false;
    }
    else
    {
        strcpy_s(output, MAX_CHAR_LEN, name);
        return true;
    }
}

const size_t DisneyCharacter::kDateFormatLength = 10; // yyyy-mm-dd

bool validateDate(char* output, const char* date)
{
    bool isNegative = date[0] == '-';
    if (isNegative) date++;

    if (strlen(date) == DisneyCharacter::kDateFormatLength)
    {
        int yyyy = 0, mm = 0, dd = 0;
        if (sscanf_s(date, "%4d-%2d-%2d", &yyyy, &mm, &dd) == 3)
        {
            if (isNegative) date--;

            strcpy_s(output, MAX_CHAR_LEN, date);
            return true;
        }
    }

    return false;
}

bool validateNum(int& output, int num)
{
	bool valid = num >= 0;
	output = valid ? num : 0;
	return valid;
}

bool validatePark(char& output, char park)
{
    switch (park)
    {
    case 'M':
    case 'S':
    case 'A':
    case 'E':
    case 'C':
        output = park;
        return true;
    case 'N':
    default:
        output = 'N';
        return false;
    }
}

DisneyCharacter::DisneyCharacter(const char* name, const char* creationDate, int numMovies, char whichPark)
{
	validateName(this->name, name);
	validateDate(this->creationDate, creationDate);
    validateNum(this->numMovies, numMovies);
	validatePark(this->whichPark, whichPark);
}

DisneyCharacter::DisneyCharacter(const char* name, const char* creationDate)
{
	validateName(this->name, name);
	validateDate(this->creationDate, creationDate);
    validateNum(numMovies, 0);
    validatePark(whichPark, 'P');
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
	return validateNum(numMovies, num);
}

bool DisneyCharacter::SetWhichPark(char park)
{
    return validatePark(whichPark, park);
}

void DisneyCharacter::ShowInfo(void)
{
    printf("# Disney character info #\n");
    printf("Name:\n%s\n", name);
    printf("Creation date:\n%s\n", creationDate);
    printf("Number of movies:\n%d\n", numMovies);
    printf("Which park:\n%c\n", whichPark);
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

