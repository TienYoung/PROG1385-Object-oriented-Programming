#include <cstdio>

#include "assessGrade.h"

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
			FILE* file = nullptr;
			fopen_s(&file, filename, "r");
			if (file == nullptr)
			{
				printf("**File I / O ERROR\n");
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

