#include "assessGrade.h"

#include <cstdio>
#include <cstring>

void assessGrade(char* letter)
{
	if (strcmp(letter, "I"))
	{
		printf("Student has Special Situation : I (Incomplete)\n");
	}

	if (strcmp(letter, "Q"))
	{
		printf("Student has Special Situation : DNA (Did Not Attend)\n");
	}

	switch (letter[0])
	{
	case 'A':
		if (letter[1] == '+')
			assessGrade(95.0);
		else
			assessGrade(85.0);
		break;
	case 'B':
		if (letter[1] == '+')
			assessGrade(77.0);
		else
			assessGrade(75.0);
		break;
	case 'C':
		if (letter[1] == '+')
			assessGrade(67.0);
		else
			assessGrade(62.0);
		break;
	case 'D':
		assessGrade(57.0);
		break;
	case 'F':
		assessGrade(50.0);
		break;
	default:
		// TODO: invalid letter
		break;
	}
}

void assessGrade(double grade)
{
	printf("Student achieved %.2f % which is a %s condition.\n", grade, grade > 54.5 ? "PASS" : "FALL");
}

bool assessGrade(int, int, int, int, int)
{

}


