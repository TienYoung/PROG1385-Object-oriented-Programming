#include <cstring>
#include <cstdio>

#define MAX_CHARS 50

class DisneyCharacter
{
public:
    DisneyCharacter(const char* name, const char* createDate, int numMovies, char whichPark);
    DisneyCharacter(const char* name, const char* createDate);
    ~DisneyCharacter();

    void ShowInfo(void);
    bool PlaceCharacter(char whichPark);
    void SameMovies(DisneyCharacter& anotherCharacter);


    inline const char* GetName() const { return name; };
    inline const char* GetCreationDate() const{ return creationDate; };
    inline int GetNumMovies() const { return numMovies; };
    inline char GetWhichPark() const { return whichPark; };

    void SetName(const char* name) { strcpy_s(this->name, MAX_CHARS, name); }

    bool SetCreationDate(const char* date) 
    {
        char* yyyy = nullptr;
        char* mm = nullptr;
        char* dd = nullptr;
        if (sscanf_s(date, "%s-%s-%s", yyyy, 4, mm, 2, dd, 2) != 3)
        {
            return false;
        }
        else
        {
            // TODO: validate the numbers.
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
    char name[50];
    char creationDate[50];
    int numMovies;
    char whichPark;
};

