#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define the struct for static array
typedef struct
{
  int data[MAX_SIZE];
  int size;
} StaticArray;

// Function declarations
void initializeStaticArray(StaticArray *arr);
bool insertAtEnd(StaticArray *arr, int element);
bool insertAtIndex(StaticArray *arr, int element, int index);
bool removeAtIndex(StaticArray *arr, int index);
int getElement(StaticArray *arr, int index);
void updateElement(StaticArray *arr, int element, int index);
int searchElement(StaticArray *arr, int element);
bool isFull(StaticArray *arr);
bool isEmpty(StaticArray *arr);
void displayArray(StaticArray *arr);
int getSize(StaticArray *arr);

int main()
{
  StaticArray arr;
  initializeStaticArray(&arr);

  insertAtIndex(&arr, 10, 0);
  insertAtIndex(&arr, 20, 1);
  insertAtIndex(&arr, 30, 2);
  insertAtIndex(&arr, 40, 3);
  insertAtEnd(&arr, 50);

  printf("Array after insertion:\n");
  displayArray(&arr);

  removeAtIndex(&arr, 2);

  printf("Array after removing element at index 2:\n");
  displayArray(&arr);

  int element = getElement(&arr, 1);
  printf("Element at index 1: %d\n", element);

  updateElement(&arr, 50, 1);
  printf("Array after updating element at index 1:\n");
  displayArray(&arr);

  int index = searchElement(&arr, 50);
  printf("Element 50 found at index: %d\n", index);

  printf("Is array full? %s\n", isFull(&arr) ? "Yes" : "No");
  printf("Is array empty? %s\n", isEmpty(&arr) ? "Yes" : "No");
  printf("Size of array: %d\n", getSize(&arr));
  return 0;
}

void initializeStaticArray(StaticArray *arr)
{
  arr->size = 0;
}

bool insertAtEnd(StaticArray *arr, int element)
{
  if (arr->size >= MAX_SIZE)
    return false; // array is full

  arr->data[arr->size] = element;
  arr->size++;
  return true;
}

bool insertAtIndex(StaticArray *arr, int element, int index)
{
  // check if index is correct
  if (index < 0 || arr->size < index || MAX_SIZE <= index)
    return false; // Index out of bounds or invalid
  if (arr->size >= MAX_SIZE)
    return false; // array is full

  for (int i = arr->size; i > index; i--)
  {
    arr->data[i] = arr->data[i - 1];
  }
  arr->data[index] = element;
  arr->size++;
  return true;
}

bool removeAtIndex(StaticArray *arr, int index)
{
  if (index < 0 || arr->size <= index)
    return false;

  for (int i = index; i < arr->size; i++)
    arr->data[i] = arr->data[i + 1];

  arr->size--;
  return true;
}

int getElement(StaticArray *arr, int index)
{
  if (index < 0 || arr->size <= index)
    return -1;

  return arr->data[index];
}

void updateElement(StaticArray *arr, int element, int index)
{
  if (index < 0 || arr->size <= index)
  {
    printf("Index out of bounds\n");
    return;
  }
  int previousElement = arr->data[index];
  arr->data[index] = element;
  printf("Element %d at index %d is now %d \n", previousElement, index, arr->data[index]);
  return;
}

int searchElement(StaticArray *arr, int element)
{
  for (int i = 0; i < arr->size; i++)
  {
    if (arr->data[i] == element)
      return i; // return the index
  }
  return -1; // element not found
}

bool isFull(StaticArray *arr)
{
  return arr->size >= MAX_SIZE;
}

bool isEmpty(StaticArray *arr)
{
  return arr->size == 0;
}

void displayArray(StaticArray *arr)
{
  if (arr == NULL)
  {
    printf("Array is null\n");
    return;
  }
  for (int i = 0; i < arr->size; i++)
    printf("arr[%d]=%d \n", i, arr->data[i]);
}

int getSize(StaticArray *arr)
{
  return arr->size;
}