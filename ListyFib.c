// Joshua Frazer jo227789
// COP 3502, Spring 2020
// Using Atom & Linux Bash Shell on Windows 10.
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "ListyFib.h"

// Auxiliary Functions
Node *createNode(int data);
ListyInt *createListyInt();
int findMax(int a, int b);
int findIntLength(unsigned int n);
int power(int n, int p);
void addByN(ListyInt *a, ListyInt *bSum);

// listyAdd function to add two linked list together
ListyInt *listyAdd(ListyInt *p, ListyInt *q)
{
    int maxLength, i, sum = 0, carry = 0;
    ListyInt *r = createListyInt();
    Node *tempP, *tempQ, *tempR;

    // Checks to see if either linked list is NULL
    if (p == NULL || q == NULL)
        return NULL;

    // Checks head to determine whether it is NULL or not to start operations
    if (r->head == NULL)
        r->head = createNode((p->head->digit + q->head->digit) % 10);

    // Checks if linked lists carry only one number that when added up must need a carry or not
    if ((p->head->digit + q->head->digit) >= 10 && p->head->next == NULL && q->head->next == NULL)
    {
        r->head->next = createNode(1);
        tempR = r->head->next;
        r->length++;
    }
    else
    {
        carry = (p->head->digit + q->head->digit >= 10) ? 1 : 0;
        tempR = r->head;
    }

    // Grabs max length of the operation depending on the size of linked list p or q
    maxLength = findMax(p->length, q->length);

    // Stores the linked list in a temporary pointer that will be manipulated for function
    tempP = p->head;
    tempQ = q->head;
    // Starts adding through both linked lists to store into a seperate linked list, r
    for (i = 1; i < maxLength; i++)
    {
        // Validates that next digit pointer is not NULL to tally sum of both linked list
        if (tempP->next != NULL && tempQ->next != NULL)
        {
            sum = tempP->next->digit + tempQ->next->digit;
            tempP = tempP->next;
            tempQ = tempQ->next;
        }
        // Validates p's next digit pointer and then only adds it's digit to r's
        else if (tempP->next != NULL)
        {
            sum = tempP->next->digit;
            tempP = tempP->next;
        }
        // Validates q's next digit pointer and then only adds it's digit to r's
        else if (tempQ->next != NULL)
        {
            sum = tempQ->next->digit;
            tempQ = tempQ->next;
        }

        // Applies the carry to the sum that has been calculated thus far
        sum += carry;
        // Reinitializes carry to 0
        carry = 0;

        // Checks sum is greater than or equal to 10 to add node with carry or not
        if (sum >= 10)
        {
            tempR->next = createNode(sum % 10);
            carry = 1;
            r->length++;
            if (tempP->next == NULL && tempQ->next == NULL)
            {
                tempR->next->next = createNode(carry);
                r->length++;
            }
        }
        // Checks sum is less than 10 to add a node without any carry
        else if (sum < 10)
        {
            tempR->next = createNode(sum);
            r->length++;
        }
        // Moves on through r to capture other values for digit and initializes sum to 0
        tempR = tempR->next;
        sum = 0;
    }

    return r;
}

ListyInt *destroyListyInt(ListyInt *listy)
{
    Node *current;
    Node *temp;

    // Checks if linked list passed is NULL
    if (listy == NULL)
        return NULL;

    // Pointer to hold linked list for freeing purposes
    current = listy->head;

    // free loop for linked list
    while (current != NULL)
    {
        temp = current->next;
        free(current);
        current = temp;
    }

    // frees the last bit of linked list
    free(listy);

    return NULL;
}

ListyInt *stringToListyInt(char *str)
{
    int i, length;
    ListyInt *list;
    Node *temp;
    // Checks if str passed is NULL
    if (str == NULL)
        return NULL;
    // Checks str if sent blank to create node of 0
    if (str == "")
    {
        list->head = createNode(0);
        return list;
    }

    // Creates new linked list and checks if it is NULL after dynamic allocation
    list = createListyInt();
    if (list == NULL)
        return NULL;

    // Captures length of string to determine total iterations through new list
    length = strlen(str);
    // Initializes the length of the new linked list with str length
    list->length = length;
    // Proceeds to check whether list head is NULL to start iterative approach
    if (list->head == NULL)
        list->head = createNode(*(str+(length-1))-48);

    // Temporary pointer to use for list so list is not lost in memory
    temp = list->head;

    // Begins inserting each element of str into linked list
    for (i = 1; i < length; i++)
    {
        temp->next = createNode(*(str+((length-1)-i))-48);
        temp = temp->next;
    }

    return list;
}

char *listyIntToString(ListyInt *listy)
{
    int i;
    char *array;
    Node *temp;

    // Checks if linked list passed to function is NULL
    if (listy == NULL)
        return NULL;

    // Dynamically allocates memory for a string array
    array = malloc(sizeof(char) * (listy->length + 1));
    // Checks if array is NULL and frees
    if (array == NULL)
    {
      free(array);
      return NULL;
    }

    // Temporary pointer to use for list so list is not lost in memory
    temp = listy->head;
    // Sets the last element in array to NULL sentinel character
    array[listy->length] = '\0';
    // Sets last element of the array with the first value of the linked list
    array[listy->length-1] = temp->digit + 48;
    // Begins iterative approach to setting array elements from the passed list
    for (i = 1; i < listy->length; i++)
    {
        array[(listy->length - 1) - i] = temp->next->digit + 48;
        temp = temp->next;
    }

    return array;
}

ListyInt *uintToListyInt(unsigned int n)
{
    int i, length, quotient;
    ListyInt *list = createListyInt();
    Node *temp;

    // Checks if dynamically allocated linked list is NULL
    if (list == NULL)
        return NULL;

    // Finds the length of the list by calling auxially function
    length = findIntLength(n);
    // Sets length of list with length received from unsigned int passed to function
    list->length = length;
    // Checks if list head is NULL to begin iterative approach
    if (list->head == NULL)
        list->head = createNode(n % 10);

    // Stores value after first element
    n /= 10;
    // Temporary pointer to use for list so list is not lost in memory
    temp = list->head;

    // Sets values in linked list from continuously dividing passed unsigned int
    for (i = 1; i < length; i++)
    {
        temp->next = createNode(n % 10);
        n /= 10;
        temp = temp->next;
    }

    return list;
}

unsigned int *listyIntToUint(ListyInt *listy)
{
  int i;
  unsigned int *uInt;
  Node *temp;
  // Checks if linked list passed to function is NULL
  if (listy == NULL)
      return NULL;
  // Checks if list length is bigger than the length of the biggest unsigned int
  if (listy->length > findIntLength(UINT_MAX))
      return NULL;
  // Dynamically allocates space for unsigned int
  uInt = malloc(sizeof(unsigned int) * 1);
  // Validates if uInt is NULL then frees it
  if (uInt == NULL)
  {
      free(uInt);
      return NULL;
  }

  // Temporary pointer to use for list so list is not lost in memory
  temp = listy->head;
  // Sets first digit in linked list to uInt
  *uInt = temp->digit ;
  // Keeps adding the next digit with a power of 10 in list to uInt
  for (i = 1; i < listy->length; i++)
  {
      *uInt += (temp->next->digit * power(10, i));
      temp = temp->next;
  }
  return uInt;
}

void plusPlus(ListyInt *listy)
{
  Node *temp;
  // Check if linked list passed to function is NULL or not
  if (listy == NULL)
      return;

  // Temporary pointer to use for list so list is not lost in memory
  temp = listy->head;
  // Adds 1 to first digit in linked list
  temp->digit++;
  // Adds carry to next node if adding 1 causes the value to hit 10
  while (temp->digit >= 10)
  {
      temp->digit %= 10;
      if (temp->next == NULL)
      {
          temp->next = createNode(1);
          listy->length++;
      }
      else
          temp->next->digit++;

      temp = temp->next;
  }
}

ListyInt *fib(unsigned int n)
{
    int i = 0;
    ListyInt *baseOneList = createListyInt(),
             *baseTwoList = createListyInt(),
             *temp1List,
             *temp2List;
    Node *temp;

    // while loop to establish fibonacci's sequence in O(n+m) runtime
    while (i <= n)
    {
        // Fibonacci's base case f(0)
        if (i == 0)
        {
            baseOneList->head = createNode(0);
        }
        // Fibonacci's base case f(1)
        else if (i == 1)
        {
            baseTwoList->head = createNode(1);
        }
        // All even Fibonacci cases
        else if (i % 2 == 0)
        {
            addByN(baseTwoList, baseOneList);
        }
        // All odd Fibonacci cases
        else if (i % 2 == 1)
        {
            addByN(baseOneList, baseTwoList);
        }
        i++;
    }

    // Choose which case to return and frees opposite case
    if (n % 2 == 0)
    {
        destroyListyInt(baseTwoList);
        return baseOneList;
    }
    else
    {
        destroyListyInt(baseOneList);
        return baseTwoList;
    }
}

double difficultyRating(void)
{
    return 2.0;
}

double hoursSpent(void)
{
    return 9.0;
}

// Auxiliary function to create a node
Node *createNode(int data)
{
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
    {
        free(node);
        return NULL;
    }

    node->digit = data;
    node->next = NULL;

    return node;
}

// Auxiliary function to create a list
ListyInt *createListyInt()
{
    ListyInt *list = malloc(sizeof(ListyInt));

    if (list == NULL)
    {
        free(list);
        return NULL;
    }

    list->head = NULL;
    list->length = 1;

    return list;
}

// Auxiliary function to find max of two integers
int findMax(int a, int b)
{
    return (a > b) ? a : b;
}

// Auxiliary function to find length of an unsigned int
int findIntLength(unsigned int n)
{
    int counter = 0;

    if (n == 0)
        return 1;

    while (n != 0)
    {
        n /= 10;
        counter++;
    }

    return counter;
}

// Auxiliary function of pow(a, b) since complications at compile
int power(int n, int p)
{
    if (p == 0)
        return 1;

    return n * power(n, p-1);
}

// Auxiliary function very similar to listyAdd but doesn't dynamically
// allocate a seperate linked list
void addByN(ListyInt *a, ListyInt *bSum)
{
  int maxLength, i, sum = 0, carry = 0;
  Node *tempA, *tempB;
  if (a == NULL || bSum == NULL)
      return;

  sum = (a->head->digit + bSum->head->digit);

  if (sum >= 10 && a->head->next == NULL && bSum->head->next == NULL)
  {
      bSum->head->digit = sum % 10;
      bSum->head->next = createNode(1);
      tempB = bSum->head->next;
      bSum->length++;
  }
  else
  {
      carry = (a->head->digit + bSum->head->digit >= 10) ? 1 : 0;
      bSum->head->digit = sum % 10;
  }

  maxLength = findMax(a->length, bSum->length);

  tempA = a->head;
  tempB = bSum->head;
  for (i = 1; i < maxLength; i++)
  {
      if (tempA->next != NULL && tempB->next != NULL)
      {
          sum = tempA->next->digit + tempB->next->digit;
      }
      else if (tempA->next != NULL)
      {
          tempB->next = createNode(0);
          sum = tempA->next->digit;
          bSum->length++;
      }
      else if (tempB->next != NULL)
      {
          tempA->next = createNode(0);
          sum = tempB->next->digit;
          a->length++;
      }

      sum += carry;
      carry = 0;

      if (sum >= 10)
      {
          tempB->next->digit = sum % 10;
          carry = 1;
          if (tempA->next->next == NULL && tempB->next->next == NULL && carry == 1)
          {
              tempB->next->next = createNode(carry);
              bSum->length++;
          }
      }
      else if (sum < 10)
      {
          tempB->next->digit = sum;
      }
      tempA = tempA->next;
      tempB = tempB->next;
      sum = 0;
  }
}
