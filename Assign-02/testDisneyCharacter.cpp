#include "DisneyCharacter.h"

int main(void)
{
	DisneyCharacter mickey("mickey", "1929-01-01", 100, 'M');
	DisneyCharacter minnie("minnie", "1930-01-01");

	minnie.SameMovies(mickey);

	mickey.ShowInfo();
	minnie.ShowInfo();

	minnie.SetWhichPark('E');

	return 0;
}