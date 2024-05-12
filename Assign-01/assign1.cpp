#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "assessGrade.h"


void parseUserInput(const char*);

int main()
{
	while(true)
	{
		printf("Enter Student's Grade(s) >>> ");
		char buffer[MAX_CHARS] = "";
		fgets(buffer, MAX_CHARS, stdin);
		char str[MAX_CHARS] = "";
		sscanf_s(buffer, "%[^\n]s", str, MAX_CHARS);
		if (str[0] == 'X' && str[1] == '\0')
		{
			printf("Exiting program...\n");
			return 0;
		}
		else if (str[0] == 'Z' && str[1] == ' ')
		{
			const char* filename = &str[2];
			FILE* file = fopen(filename, "r");
			if (file == nullptr)
			{
				printf("Error: File can't be opened or doesn't exit!\n");
				continue;
			}

			while (fgets(buffer, MAX_CHARS, file) != nullptr)
			{
				parseUserInput(buffer);
			}
			if (feof(file) || ferror(file))
			{
				fclose(file);
				continue;
			}
		}
		else
		{
			parseUserInput(buffer);
		}
	}

	return 0;
}

void parseUserInput(const char* str)
{
	sscanf_s(str, "%d %d %d %d %d");

}

