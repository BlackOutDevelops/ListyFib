// Sean Szumlanski
// COP 3502, Spring 2020

// ======================
// ListyFib: testcase03.c
// ======================
// Tests for a variety of functions: stringToListyInt(), listyIntToUint(), and destroyListyInt().


#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "ListyFib.h"

// Recursive helper function for printing the digits in a linked list in reverse order.
void listyPrintHelper(Node *current)
{
	if (current == NULL)
		return;

	listyPrintHelper(current->next);
	printf("%d", current->digit);
}

// Print a ListyInt (followed by a newline character).
void listyPrint(ListyInt *p)
{
	if (p == NULL || p->head == NULL)
	{
		printf("(null pointer)\n");
		return;
	}

	listyPrintHelper(p->head);
	printf("\n");
}

int main(void)
{
	unsigned int *temp;
	ListyInt *p;

	listyPrint(p = stringToListyInt("12345"));
	printf("%u\n", *(temp = listyIntToUint(p)));
	free(temp);
	destroyListyInt(p);

	listyPrint(p = stringToListyInt("354913546879519843519843548943513179"));
	temp = listyIntToUint(p);
	assert(temp == NULL);
	destroyListyInt(p);

	listyPrint(p = stringToListyInt(NULL));
	temp = listyIntToUint(p);
	assert(temp == NULL);
	destroyListyInt(p);

	listyPrint(p = uintToListyInt(246810));
	printf("%u\n", *(temp = listyIntToUint(p)));
	free(temp);
	destroyListyInt(p);

	listyPrint(p = uintToListyInt(0));
	printf("%u\n", *(temp = listyIntToUint(p)));
	free(temp);
	destroyListyInt(p);

	listyPrint(p = uintToListyInt(INT_MAX));
	printf("%u\n", *(temp = listyIntToUint(p)));
	free(temp);
	destroyListyInt(p);

	listyPrint(p = uintToListyInt(UINT_MAX));
	printf("%u\n", *(temp = listyIntToUint(p)));
	free(temp);
	destroyListyInt(p);

	return 0;
}
