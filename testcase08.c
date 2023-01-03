// Sean Szumlanski
// COP 3502, Spring 2020

// ======================
// ListyFib: testcase08.c
// ======================
// Boundary checks to help ensure the difficultyRating() and hoursSpent()
// functions are implemented correctly.


#include <stdio.h>
#include "ListyFib.h"

int main(void)
{
	int success = 1;

	if (difficultyRating() < 1.0 || difficultyRating() > 5.0)
		success = 0;
	if (hoursSpent() <= 0.0)
		success = 0;

	printf("%s\n", success ? "Hooray!" : "fail whale :(");

	return 0;
}
