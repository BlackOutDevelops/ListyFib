// Sean Szumlanski
// COP 3502, Spring 2020

// ======================
// ListyFib: testcase01.c
// ======================
// This test is designed primarily to check the internal structure of a ListyInt created by the
// uintToListyInt() function. You should write a similar test for stringToListyInt().


#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include "ListyFib.h"

int main(void)
{
	ListyInt *listy;
	Node *temp;


	// Create new ListyInt, check its internals, and then destroy it.
	listy = uintToListyInt(0);
	assert(listy != NULL);
	assert(listy->head != NULL);

	temp = listy->head;
	assert(temp != NULL);
	assert(temp->digit == 0);

	temp = temp->next;
	assert(temp == NULL);

	listy = destroyListyInt(listy);


	// Create new ListyInt, check its internals, and then destroy it.
	listy = uintToListyInt(1);
	assert(listy != NULL);
	assert(listy->head != NULL);

	temp = listy->head;
	assert(temp != NULL);
	assert(temp->digit == 1);

	temp = temp->next;
	assert(temp == NULL);

	listy = destroyListyInt(listy);


	// Create new ListyInt, check its internals, and then destroy it.
	listy = uintToListyInt(981325);
	assert(listy != NULL);
	assert(listy->head != NULL);

	temp = listy->head;
	assert(temp != NULL);
	assert(temp->digit == 5);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 2);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 3);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 1);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 8);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 9);

	temp = temp->next;
	assert(temp == NULL);

	listy = destroyListyInt(listy);

	printf("%u\n", UINT_MAX);


	// Create new ListyInt, check its internals, and then destroy it.
	listy = uintToListyInt(UINT_MAX);
	assert(listy != NULL);
	assert(listy->head != NULL);

	temp = listy->head;
	assert(temp != NULL);
	assert(temp->digit == 5);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 9);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 2);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 7);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 6);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 9);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 4);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 9);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 2);

	temp = temp->next;
	assert(temp != NULL);
	assert(temp->digit == 4);

	temp = temp->next;
	assert(temp == NULL);

	listy = destroyListyInt(listy);

	assert(listy == NULL);


	// The goal is to reach this line without any assert() statements failing.
	printf("Hooray!\n");


	return 0;
}
