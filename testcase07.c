// Sean Szumlanski
// COP 3502, Spring 2020

// ======================
// ListyFib: testcase07.c
// ======================
// Essential test of the fib() function. This one is much longer than testcase06.c.


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
	int i;
	ListyInt *p;

	for (i = 0; i <= 1000; i++)
	{
		printf("F(%d) = ", i);
		listyPrint(p = fib(i));
		destroyListyInt(p);
	}

	return 0;
}
