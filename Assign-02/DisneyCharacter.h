#include <cstring>
#include <cstdio>
#include <cstdlib>

#define MAX_CHAR_LEN 50
#define TRUNCATE_LEN 46

class DisneyCharacter
{
public:
    DisneyCharacter(const char* name, const char* creationDate, int numMovies, char whichPark);
    DisneyCharacter(const char* name, const char* creationDate);
    ~DisneyCharacter();

    // Accessors
    const char* GetName() const;
    const char* GetCreationDate() const;
    int GetNumMovies() const;
    char GetWhichPark() const;

    // Mutators
    bool SetNumMovies(int num);
    bool SetWhichPark(char park);

    // Methods
    void ShowInfo(void);
    bool PlaceCharacter(char whichPark);
    void SameMovies(DisneyCharacter& anotherCharacter);

    static const size_t kDateFormatLength; // yyyy-mm-dd
    static const int kZero; // 0
    static const char kNotPlaced; // 'N'

private:
    char name[MAX_CHAR_LEN];
    char creationDate[MAX_CHAR_LEN];
    int numMovies;
    char whichPark;
};

