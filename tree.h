#ifndef TREE_H
#define TREE_H

typedef struct Node Node;

struct Node* newNode(int value);
struct Node* insertNode(struct Node* head, int value);
void printInOrder(struct Node* head);
void printPostOrder(struct Node* head);
void printPreOrder(struct Node* head);
void printReverseInOrder(struct Node* head);
void printReversePostOrder(struct Node* head);
void printReversePreOrder(struct Node* head);
void deleteTree(struct Node* head);

#endif