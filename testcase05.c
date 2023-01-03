// Sean Szumlanski
// COP 3502, Spring 2020

// ======================
// ListyFib: testcase05.c
// ======================
// Tests for a variety of functions: uintToListyInt(), listyAdd(), and destroyListyInt().


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
}

int main(void)
{
	int i;
	ListyInt *p, *q, *r;

	// Calculate INT_MAX + 1.
	p = uintToListyInt(INT_MAX);
	q = uintToListyInt(1);
	r = listyAdd(p, q);

	// Demonstrate overflow.
	printf("Overflow style:\n%d + %d = %d\n\n", INT_MAX, 1, INT_MAX + 1);

	// Print result of INT_MAX + 1 with ListyInts.
	printf("ListyInt style:\n");
	listyPrint(p);
	printf(" + ");
	listyPrint(q);
	printf(" = ");
	listyPrint(r);
	printf("\n\n");

	// Free memory.
	destroyListyInt(p);
	destroyListyInt(q);
	destroyListyInt(r);


	// Now calculate UINT_MAX + 1.
	p = uintToListyInt(UINT_MAX);
	q = uintToListyInt(1);
	r = listyAdd(p, q);

	// Demonstrate overflow.
	printf("Overflow style:\n%u + %u = %u\n\n", UINT_MAX, 1, UINT_MAX + 1);

	// Print result of UINT_MAX + 1 with ListyInts.
	printf("ListyInt style:\n");
	listyPrint(p);
	printf(" + ");
	listyPrint(q);
	printf(" = ");
	listyPrint(r);
	printf("\n");

	// Free memory.
	destroyListyInt(p);
	destroyListyInt(q);
	destroyListyInt(r);


	return 0;
}
