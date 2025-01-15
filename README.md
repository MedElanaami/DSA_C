# Data Structures and Algorithms in C language

## Best Practice

`For best practices`, functions that **_modify the structure_** of a data structure (such as adding or removing elements) should return the `updated structure`. Functions that **_modify the data_** within the elements or perform operations that do not change the structure should return `void`.

```c
// For traversal:
Node *tmp = head;  // Correct ✓

// Only use malloc when creating new nodes:
Node *newNode = (Node *)malloc(sizeof(Node));  // For new nodes ✓
```

## Arrays

## [Linked List](./LinkedList)

## [Stacks](./stack/)

## [Queues](./queues/)

## [Trees](./binaryTree/)

## Graphs

## Searching Algorithms

## Sorting Algorithms
