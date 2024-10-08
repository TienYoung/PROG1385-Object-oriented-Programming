/*
 * FILE : assessGrad.cpp
 * PROJECT : PROG1385 - ASSIGNMENT 1
 * PROGRAMMER : Tian Yang
 * FIRST VERSION : 2024-05-12
 * DESCRIPTION :
 * Implementation of parseUserInput() and assessGrade()
 */


#include "assessGrade.h"

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>

/*
Function: parseUserInput()
Description:
	Examine user input and determine use which assessGrade function.
Parameter: 
	const char* str: representing the user�s input
Return Value: 
	void: 
*/
void parseUserInput(const char* str)
{
	char s[5][MAX_CHARS] = { };
	char temp[MAX_CHARS] = "";
	int num = sscanf_s(str, "%s %s %s %s %s %s",
		s[0], MAX_CHARS,
		s[1], MAX_CHARS,
		s[2], MAX_CHARS,
		s[3], MAX_CHARS,
		s[4], MAX_CHARS,
		temp, MAX_CHARS);
	if (num == 1)
	{
		if (isdigit(s[0][0]))
		{
			assessGrade(atof(s[0]));
		}
		else
		{
			assessGrade(s[0]);
		}
	}
	else if (1 < num && num < 6)
	{
		int g[5] = { 0 };
		for (int i = 0; i < num; i++)
		{
			g[i] = atoi(s[i]);
		}
		assessGrade(g, num);
	}
	else
	{
		printInvalidInput();
	}
}

/*
Function: assessGrade()
Description:
	Assess a letter grade
Parameter:
   char* letter: a letter grade or special situation
Return Value:
   void:
*/
void assessGrade(char* letter)
{
	if (strcmp(letter, "A+") == 0)
	{
		assessGrade(95.0);
	}
	else if (strcmp(letter, "A") == 0)
	{
		assessGrade(85.0);
	}
	else if (strcmp(letter, "B+") == 0)
	{
		assessGrade(77.0);
	}
	else if (strcmp(letter, "B") == 0)
	{
		assessGrade(72.0);
	}
	else if (strcmp(letter, "C+") == 0)
	{
		assessGrade(67.0);
	}
	else if (strcmp(letter, "C") == 0)
	{
		assessGrade(62.0);
	}
	else if (strcmp(letter, "D") == 0)
	{
		assessGrade(57.0);
	}
	else if (strcmp(letter, "F") == 0)
	{
		assessGrade(50.0);
	}
	else if (strcmp(letter, "I") == 0)
	{
		printf("Student has Special Situation : I (Incomplete)\n");
	}
	else if (strcmp(letter, "Q") == 0)
	{
		printf("Student has Special Situation : Q (Withdrawal After Drop/Refund Date)\n");
	}
	else if (strcmp(letter, "AU") == 0)
	{
		printf("Student has Special Situation : AU (Audit Condition)\n");
	}
	else if (strcmp(letter, "DNA") == 0)
	{
		printf("Student has Special Situation : DNA (Did Not Attend)\n");
	}
	else if (strcmp(letter, "I/P") == 0)
	{
		printf("Student has Special Situation : I/P (In Process)\n");
	}
	else
	{
		printInvalidInput();
	}
}

/*
Function: assessGrade()
Description:
	Assess the final mark.
Parameter:
   double grade: the final mark
Return Value:
   void:
*/
void assessGrade(double grade)
{
	if (grade > 100.0 || grade < 0.0)
	{
		printInvalidInput();
		return;
	}
	printf("Student achieved %.2f %% which is a %s condition.\n", grade, grade >= 54.5 ? "PASS" : "FALL");

}

/*
Function: assessGrade()
Description:
	Assess a letter grade
Parameter:
   int g[]: assignment marks
   int num: the number of assignments
Return Value:
   void:
*/
void assessGrade(int g[], int num)
{
	double sum = 0.0;
	for (int i = 0; i < num; i++)
	{
		if (g[i] < 0.0 || g[i] > 100.0)
		{
			printInvalidInput();
			return;
		}
		sum += g[i];
	}
	assessGrade(sum * 0.2);
}


/*
Function: printInvalidInput()
Description:
	print the error info.
Parameter:
   void:
Return Value:
   void:
*/
void printInvalidInput()
{
	printf("**ERROR : Invalid Input\n");
}

