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

/* Insert at position*/
Node *insert_Pos(Node *head)
{
  int val, pos;
  printf("Enter the value to be inserted\n");
  scanf("%d", &val);
  printf("Enter the position\n");
  scanf("%d", &pos);

  if (pos <= 0)
    head = insert_Beg(head, val);

  else if (pos >= length_List(head))
    head = insert_End(head, val);

  else
  {
    int count = 0;
    Node *newNode = create_Node(val);
    Node *tmp = head;

    while (tmp->next && count < pos - 1)
    {
      count++;
      tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    return (Node *)head;
  }
}

Node *create_List()
{
  int nbrElements;
  printf("How many elements you want to insert?");
  scanf("%d", &nbrElements);

  if (nbrElements <= 0)
    return NULL;

  Node *head = NULL;

  for (int i = 0; i < nbrElements; i++)
  {
    int val;
    printf("Enter data for node %d: ", i + 1);
    scanf("%d", &val);
    if (i == 0)
      head = create_Node(val);
    else
      head = insert_End(head, val);
  }

  return (Node *)head;
}

/*Delete node*/

// Delete the first node
Node *delete_Beg(Node *head)
{
  if (!head)
  {
    printf("Linked list doesnt exist or empty");
    return NULL;
  }

  Node *newNode = head->next;
  free(head);
  return (Node *)newNode;
}

// Delete the last node
Node *delete_End(Node *head)
{
  if (!head)
  {
    printf("Linked list doesnt exist or empty");
    return NULL;
  }

  // If there is 1 elem in list
  if (head->next == NULL)
  {
    free(head);
    return NULL;
  }
  // Else go for the last element
  Node *tmp = head;
  while (tmp->next->next)
  {
    tmp = tmp->next;
  }

  free(tmp->next);
  tmp->next = NULL;
  return (Node *)head;
}

// Delete at position
Node *delete_Pos(Node *head, int pos)
{

  if (!head)
  {
    printf("Linked list doesnt exist or empty\n");
    return (Node *)head;
  }

  // check if position not in the lenght of linked list
  if (pos < 1 || length_List(head) < pos)
  {
    printf("Position not valid\n");
    return (Node *)head;
  }

  // if the position of first element
  if (pos == 1)
  {
    head = delete_Beg(head);
    return (Node *)head;
  }

  if (length_List(head) == pos)
  {
    head = delete_End(head);
    return (Node *)head;
  }

  Node *tmp = head;
  for (int i = 1; i < pos - 1; i++)
    tmp = tmp->next;

  Node *del = tmp->next;
  tmp->next = tmp->next->next;
  free(del);
  return (Node *)head;
}
void free_Node(Node *head)
{
  // Free memory
  while (head)
  {
    Node *tmp = head;
    head = head->next;
    free(tmp);
  }
}

int main()
{

  // Test with a single node
  Node *list = create_List();
  display(list);
  printf("Delete at beg\n");
  list = delete_Beg(list);
  display(list);

  printf("Delete at ent\n");
  list = delete_End(list);
  display(list);
  printf("Delete at pos\n");
  list = delete_Pos(list, 2);
  display(list);

  free_Node(list);

  return 0;
}