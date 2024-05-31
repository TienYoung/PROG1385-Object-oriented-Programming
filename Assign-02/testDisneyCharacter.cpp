#include "DisneyCharacter.h"

int main(void)
{
	DisneyCharacter micky("Micky", "1919-10-03");
	printf("Name: %s\t,Date: %s\t\n", micky.GetName(), micky.GetCreationDate());

	return 0;
}