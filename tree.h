#ifndef TREE_H
#define TREE_H

typedef struct Node Node;

//Manipulation functions
struct Node* newNode(int value);
struct Node* insertNode(struct Node* head, int value);
struct Node* deleteNode(struct Node* head, int value);
struct Node* balanceTree(struct Node* head);

//printing functions
void printInOrder(struct Node* head);
void printPostOrder(struct Node* head);
void printPreOrder(struct Node* head);
void printReverseInOrder(struct Node* head);
void printReversePostOrder(struct Node* head);
void printReversePreOrder(struct Node* head);
void printTree(struct Node* head, int indent);

//getters and setters
int numNodes(struct Node* head);
struct Node* findMin(struct Node* head);
struct Node* findMax(struct Node* head);
struct Node* getSubtree(struct Node* head, int value);

//cleanup/helper functions
struct Node* rotateLeft(struct Node* parent);
int treeToVine(struct Node **root);
struct Node* compress(struct Node* root, int m);
struct Node* vineToTree(Node *root, int count);
struct Node* generateTree(int numNodes);
void deleteTree(struct Node* head);

#endif