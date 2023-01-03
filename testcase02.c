// Sean Szumlanski
// COP 3502, Spring 2020

// ======================
// ListyFib: testcase02.c
// ======================
// Tests the stringToListyInt() and uintToListyInt() functions.


#include <limits.h>
#include <stdio.h>
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
	ListyInt *p;

	listyPrint(p = stringToListyInt("12345"));
	destroyListyInt(p);

	listyPrint(p = stringToListyInt("354913546879519843519843548943513179"));
	destroyListyInt(p);

	listyPrint(p = stringToListyInt(NULL));
	destroyListyInt(p);

	listyPrint(p = uintToListyInt(246810));
	destroyListyInt(p);

	listyPrint(p = uintToListyInt(0));
	destroyListyInt(p);

	listyPrint(p = uintToListyInt(INT_MAX));
	destroyListyInt(p);

	listyPrint(p = uintToListyInt(UINT_MAX));
	destroyListyInt(p);

	return 0;
}
