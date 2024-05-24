/*
 * FILE : assessGrad.h
 * PROJECT : PROG1385 - ASSIGNMENT 1
 * PROGRAMMER : Tian Yang
 * FIRST VERSION : 2024-05-12
 * DESCRIPTION :
 * The functions in this file are used to examine user input and assess the grade. 
 */

#define MAX_CHARS 100

void parseUserInput(const char*);

void assessGrade(char*);
void assessGrade(double);
void assessGrade(int[], int);

void printInvalidInput();
