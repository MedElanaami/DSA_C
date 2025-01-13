#include <stdio.h>
#include <stdlib.h>

/* Struct*/
typedef struct Node
{
  /* data */
  int data;
  struct Node *next;
} Node;

/*Create node*/
Node *create_Node(int val)
{
  Node *node = (Node *)malloc(sizeof(Node));

  if (!node)
  {
    printf("Erreur Allocation");
    exit(0);
  }
  // Insert data
  node->data = val;
  node->next = NULL;
  return (Node *)node;
}

/* Length of list*/
int length_List(Node *head)
{
  // Check if node exist
  if (!head)
  {
    printf("The list doesnt exsit");
    return (int)0;
  }
  int count = 0;
  // Create a tmp node
  Node *tmp = head;
  while (tmp)
  {
    count++;
    tmp = tmp->next;
  }
  return (int)count;
}

/* Display Linked List*/
void display(Node *head)
{
  if (!head)
  {
    printf("Liste is empty");
    return;
  }

  printf("Display elements in Linked List\n");
  Node *tmp = head;
  while (tmp)
  {
    printf("%d ", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}

/* Insert at the begining of the liked list*/
Node *insert_Beg(Node *head, int val)
{
  Node *newNode = create_Node(val);
  newNode->next = head;
  return (Node *)newNode;
}

/* Insert at the end of linked list*/
Node *insert_End(Node *head, int val)
{
  Node *newNode = create_Node(val);

  if (!head)
    return (Node *)newNode;

  Node *tmp = head;
  while (tmp->next)
  {
    tmp = tmp->next;
  }
  tmp->next = newNode;
  return (Node *)head;
}

Node *create_List()
{
  int nbrElements;
  printf("How many elements you want to insert? ");
  scanf("%d", &nbrElements);

  if (nbrElements <= 0)
    return NULL;

  Node *head = NULL;

  for (int i = 0; i < nbrElements; i++)
  {
    int val;
    printf("Enter data for node %d", i + 1);
    scanf("%d", &val);
    if (i == 0)
      head = create_Node(val);
    else
      head = insert_End(head, val);
  }

  return (Node *)head;
}

int main()
{

  // Test with a single node
  Node *list = create_Node(5);
  printf("Initial list: ");
  display(list);

  // Insert at beginning
  list = insert_Beg(list, 3);
  printf("After inserting 3 at beginning: ");
  display(list);

  // Insert at end
  list = insert_End(list, 7);
  printf("After inserting 7 at end: ");
  display(list);

  printf("Length of list: %d\n", length_List(list));

  // Free memory
  while (list)
  {
    Node *tmp = list;
    list = list->next;
    free(tmp);
  }

  return 0;
}