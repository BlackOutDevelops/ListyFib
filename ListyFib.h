#ifndef __LISTYFIB_H
#define __LISTYFIB_H


// Standard Struct Defintions

typedef struct Node
{
	int digit;
	struct Node *next;
} Node;

typedef struct ListyInt
{
	// The head of a linked list that holds the digits
	// of an integer, stored in reverse order.
	Node *head;

	// Number of digits in the integer (which is equal
	// to the number of nodes in the list).
	int length;
} ListyInt;


// Functional Prototypes

ListyInt *listyAdd(ListyInt *p, ListyInt *q);

ListyInt *destroyListyInt(ListyInt *listy);

ListyInt *stringToListyInt(char *str);

char *listyIntToString(ListyInt *listy);

ListyInt *uintToListyInt(unsigned int n);

unsigned int *listyIntToUint(ListyInt *listy);

void plusPlus(ListyInt *listy);

ListyInt *fib(unsigned int n);

double difficultyRating(void);

double hoursSpent(void);


#endif
