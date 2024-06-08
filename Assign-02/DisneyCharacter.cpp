#include "DisneyCharacter.h"

void regulateName(char* output, const char* name)
{
    size_t length = strlen(name) + 1;
    if (length > MAX_CHAR_LEN)
    {
        strncpy_s(output, MAX_CHAR_LEN, name, TRUNCATE_LEN - 1);
        strcat_s(output, MAX_CHAR_LEN, " ...");
    }
    else
    {
        strcpy_s(output, MAX_CHAR_LEN, name);
    }
}

const size_t DisneyCharacter::kDateFormatLength = 10; // yyyy-mm-dd

void regulateDate(char* output, const char* date)
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
        }
    }
    else
    {
        strcpy_s(output, MAX_CHAR_LEN, "");
    }
}

bool validateNum(int num)
{
	return num >= 0;
}

bool validatePark(char park)
{
    switch (park)
    {
    case 'M':
    case 'S':
    case 'A':
    case 'E':
    case 'C':
    case 'N':
        return true;
    default:
        return false;
    }
}

DisneyCharacter::DisneyCharacter(const char* name, const char* creationDate, int numMovies, char whichPark)
{
    regulateName(this->name, name);
    regulateDate(this->creationDate, creationDate);
 
    this->numMovies = validateNum(numMovies) ? numMovies : 0;
    this->whichPark = validatePark(whichPark) ? whichPark : 'N';
}

DisneyCharacter::DisneyCharacter(const char* name, const char* creationDate)
{
	regulateName(this->name, name);
	regulateDate(this->creationDate, creationDate);

    this->numMovies = 0;
    this->whichPark = 'N';
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
    bool valid = validateNum(num);
    if (valid) 
        numMovies = num;
    return valid;
}

bool DisneyCharacter::SetWhichPark(char park)
{
    bool valid = validatePark(park);
    if (valid)
        whichPark = park;
    return valid;
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

