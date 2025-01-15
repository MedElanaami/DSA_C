#include <stdio.h>
#include <stdlib.h>

// Struct of tree node
typedef struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

// Create node
TreeNode *createNode(int val)
{
  TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
  if (!newNode)
  {
    printf("Err");
    return NULL;
  }
  newNode->data = val;
  newNode->right = NULL;
  newNode->left = NULL;
  return newNode;
}

// Insert a node in a tree
TreeNode *insertNode(TreeNode *root, int val)
{
  if (!root)
  {
    return createNode(val);
  }
  if (val < root->data)
  {
    root->left = insertNode(root->left, val);
  }
  else if (root->data < val)
  {
    root->right = insertNode(root->right, val);
  }
  return root;
}

// Search a node
TreeNode *searchNode(TreeNode *root, int val)
{
  if (root == NULL || root->data == val)
  {
    return root;
  }
  if (val < root->data)
    return searchNode(root->left, val);
  // if root->data > val
  return searchNode(root->right, val);
}

// Find min
TreeNode *findMin(TreeNode *root)
{
  TreeNode *tmp = root;
  while (tmp->left != NULL)
  {
    tmp = tmp->left;
  }
  return tmp;
}

// Delete node
TreeNode *deleteNode(TreeNode *root, int val)
{
  if (root == NULL)
    return root;
  if (val < root->data)
    root->left = deleteNode(root->left, val);
  if (root->data < val)
    root->right = deleteNode(root->right, val);
}

// Pre-order traversal of the tree
void preorderTraversal(TreeNode *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}
// Post-order traversal of the tree
void postorderTraversal(TreeNode *root)
{
  if (root != NULL)
  {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
  }
}
// In-order traversal of the tree
void inorderTraversal(TreeNode *root)
{
  if (root != NULL)
  {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

int main()
{
  TreeNode *root = NULL;
  root = insertNode(root, 50);
  insertNode(root, 30);
  insertNode(root, 20);
  insertNode(root, 40);
  insertNode(root, 70);
  insertNode(root, 60);
  insertNode(root, 80);

  printf("In-order traversal: ");
  inorderTraversal(root);
  printf("\n");

  printf("Pre-order traversal: ");
  preorderTraversal(root);
  printf("\n");

  printf("Post-order traversal: ");
  postorderTraversal(root);
  printf("\n");
}