#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define END "\n"
// Struct
typedef struct Stack
{
  int data;
  struct Stack *next;
} Stack;

// Initialization of a pointer top
Stack *top = NULL;

// create stack
Stack *create_Stack(int val)
{
  Stack *newNode;
  newNode = (Stack *)malloc(sizeof(Stack));

  if (!newNode)
  {
    printf("Memory allocation error\n");
    return NULL;
  }

  newNode->data = val;
  newNode->next = NULL;
  return (Stack *)newNode;
}

/* Push */
Stack *push_Stack(Stack *top, int val)
{
  Stack *newNode = create_Stack(val);

  newNode->next = top;
  return (Stack *)newNode;
}

/* Pop */
Stack *pop_Stack(Stack *top)
{
  if (!top)
  {
    printf("Stack underflow\n");
    return NULL;
  }
  Stack *tmp = top;
  top = top->next;
  free(tmp);
  return (Stack *)top;
}

/* Peek */
int peek_Stack(Stack *top)
{
  if (!top)
  {
    printf("Stack is empty\n");
    return -1;
  }
  return (int)top->data;
}

/* Is Empty*/
bool isEmpty_Stack(Stack *top)
{
  return top == NULL;
}

/* Display */
void display_Stack(Stack *top)
{
  if (!top)
  {
    printf("Stack is empty\n");
    return;
  }
  Stack *tmp = top;
  while (tmp)
  {
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
  printf(END);
}

int main()
{
  Stack *mystack;
  mystack = create_Stack(1);
  mystack = push_Stack(mystack, 2);
  mystack = push_Stack(mystack, 3);
  mystack = push_Stack(mystack, 4);
  display_Stack(mystack);
  mystack = pop_Stack(mystack);
  display_Stack(mystack);
  printf("%d\n", peek_Stack(mystack));
  printf("%d\n", isEmpty_Stack(mystack));
}