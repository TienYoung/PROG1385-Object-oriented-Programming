#include <cstring>
#include <cstdio>

#define MAX_CHAR_LEN 50
#define DATE_FORMAT_LENGTH 11

class DisneyCharacter
{
public:
    DisneyCharacter(const char* name, const char* creationDate, int numMovies, char whichPark);
    DisneyCharacter(const char* name, const char* creationDate);
    ~DisneyCharacter();

    void ShowInfo(void);
    bool PlaceCharacter(char whichPark);
    void SameMovies(DisneyCharacter& anotherCharacter);

    const char* GetName() const;
    const char* GetCreationDate() const;
    int GetNumMovies() const;
    char GetWhichPark() const;

    void SetName(const char* name) { strcpy_s(this->name, MAX_CHAR_LEN, name); }

    bool SetCreationDate(const char* date) 
    {
        char yyyy[5] = "";
        char mm[3] = "";
        char dd[3] = "";
        if (sscanf_s(date, "%4s-%2s-%2s", yyyy, 5, mm, 3, dd, 3) != 3)
        {
            printf("error date\n");
            return false;
        }
        else
        {
            // TODO: validate the numbers.
            strcpy_s(creationDate, DATE_FORMAT_LENGTH, date);
            return true;
        }
    }
    
    bool SetNumMovies(int num) 
    { 
        bool valid = num >= 0;
        numMovies = valid ? num : 0;
        return valid;
    }
    
    bool SetWhichPark(char park)
    {
        switch (park)
        {
        case 'M':
            park = 'M';
            return true;
        case 'S':
            park = 'S';
            return true;
        case 'A':
            park = 'A';
            return true;
        case 'E':
            park = 'E';
            return true;
        case 'C':
            park = 'C';
            return true;
        case 'N':
            park = 'N';
            return true;
        default:
            park = 'N';
            return false;
        }
    }

private:
    char name[MAX_CHAR_LEN];
    char creationDate[DATE_FORMAT_LENGTH];
    int numMovies;
    char whichPark;
};

