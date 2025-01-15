#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Struct */
typedef struct Node
{
  int data;
  struct Node *next;
} Node;

typedef struct Queue
{
  Node *front;
  Node *rear;
} Queue;

/* Create Queue Node */
Node *create_Node(int val)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode)
  {
    printf("Memory allocation error\n");
    return NULL;
  }
  newNode->data = val;
  newNode->next = NULL;
  return newNode;
}

/* Create Queue */
Queue *create_Queue()
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (!queue)
  {
    printf("Memory allocation error\n");
    return NULL;
  }
  queue->front = queue->rear = NULL;
  return queue;
}

/* Enqueue */
Queue *enqueue(Queue *queue, int val)
{
  Node *newNode = create_Node(val);
  if (!newNode)
    return queue;
  // If its empty
  if (queue->rear == NULL)
  {
    queue->front = queue->rear = newNode;
    return queue;
  }
  queue->rear->next = newNode;
  queue->rear = queue->rear->next; // newNode
  return queue;
}

/* Dequeue */
Queue *dequeue(Queue *queue)
{
  if (queue->front == NULL)
  {
    printf("Queue underflow\n");
    return queue;
  }

  Node *tmp = queue->front;
  queue->front = queue->front->next;
  // In case the queue have one element
  if (queue->front == NULL)
    queue->rear = NULL;

  free(tmp);
  return queue;
}

/* Peek */
int peek(Queue *queue)
{
  if (queue->front == NULL)
  {
    printf("Queue is empty\n");
    return -1;
  }
  return queue->front->data;
}

/* Is empty */
bool isEmpty(Queue *queue)
{
  return queue->front == NULL;
}

/* Display */
void display(Queue *queue)
{
  if (!queue->front)
  {
    printf("Queue is empty\n");
    return;
  }
  Node *tmp = queue->front;
  while (tmp != NULL)
  {
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
  printf("Null\n");
}

int main()
{
  Queue *myQueue = create_Queue();

  // Enqueue elements
  myQueue = enqueue(myQueue, 1);
  myQueue = enqueue(myQueue, 2);
  myQueue = enqueue(myQueue, 3);
  myQueue = enqueue(myQueue, 4);

  // Display the queue
  printf("Queue after enqueuing 1, 2, 3, 4:\n");
  display(myQueue);

  // Dequeue an element
  myQueue = dequeue(myQueue);
  printf("Queue after dequeuing an element:\n");
  display(myQueue);

  // Peek at the front element
  int front = peek(myQueue);
  printf("Front element: %d\n", front);

  // Check if the queue is empty
  bool empty = isEmpty(myQueue);
  printf("Is the queue empty? %s\n", empty ? "Yes" : "No");

  return 0;
}