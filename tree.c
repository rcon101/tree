#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "tree.h"

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insertNode(struct Node* head, int value){
    if(head == NULL) return newNode(value);
    if(value < head->value) head->left = insertNode(head->left, value);
    else if(value > head->value) head->right = insertNode(head->right, value);
    return head;
}

struct Node* deleteNode(struct Node* head, int value) {
    if (head == NULL)
        return NULL;

    if (value < head->value) {
        head->left = deleteNode(head->left, value);
    } else if (value > head->value) {
        head->right = deleteNode(head->right, value);
    } else {
        // Node found
        if (head->left == NULL) {
            struct Node* r = head->right;
            free(head);
            return r;
        } else if (head->right == NULL) {
            struct Node* l = head->left;
            free(head);
            return l;
        } else {
            // Two children: replace with in-order successor
            struct Node* succ = findMin(head->right);
            head->value = succ->value;
            head->right = deleteNode(head->right, succ->value);
        }
    }
    return head;
}

void printInOrder(struct Node* head){
    if(head != NULL) {
        printInOrder(head->left);
        printf("%d\n", head->value);
        printInOrder(head->right);
    }
}

void printPostOrder(struct Node* head) {
    if(head!=NULL){
        printPostOrder(head->left);
        printPostOrder(head->right);
        printf("%d\n", head->value);
    }
}
void printPreOrder(struct Node* head){
    if(head!=NULL){
        printf("%d\n", head->value);
        printPreOrder(head->left);
        printPreOrder(head->right); 
    }
}
void printReverseInOrder(struct Node* head) {
    if(head != NULL) {
        printReverseInOrder(head->right);
        printf("%d\n", head->value);
        printReverseInOrder(head->left);
    }
}
void printReversePostOrder(struct Node* head){
    if(head != NULL) {
        printReversePostOrder(head->right);
        printReversePostOrder(head->left);
        printf("%d\n", head->value);
    }
}
void printReversePreOrder(struct Node* head){
    if(head != NULL) {
        printf("%d\n", head->value);
        printReversePreOrder(head->right);
        printReversePreOrder(head->left);
    }
}

void printTree(struct Node* head, int indent) {
    if(head==NULL) return;
    printTree(head->right, indent + 4);
    for(int i=0; i<indent; i++){
        printf(" ");
    }
    printf("%d\n", head->value);
    printTree(head->left, indent + 4);
}

int numNodes(struct Node* head) {
    if(head==NULL) return 0;
    return 1 + numNodes(head->left) + numNodes(head->right);
}

struct Node* findMin(struct Node* head) {
    while (head->left != NULL)
        head = head->left;
    return head;
}

struct Node* findMax(struct Node* head) {
    while (head->right != NULL)
        head = head->right;
    return head;
}

//note that when a subtree's original root is free'd, the subTree returned pointer will also be free'd.
//may want to add copySubtree to copy this subtree's data to new memory 
struct Node* getSubtree(struct Node* head, int value) {
    if(head==NULL || head->value == value) return head;
    if(value < head->value) head->left = getSubtree(head->left, value);
    else if(value > head->value) head->right = getSubtree(head->right, value);
}

struct Node* rotateLeft(struct Node* parent) {
    struct Node* child = parent->right;
    parent->right = child->right;
    child->right = parent->right->left;
    parent->right->left = child;
    return parent;
}

int treeToVine(struct Node **root) {
    struct Node *pseudo = (struct Node*)malloc(sizeof(struct Node));
    pseudo->right = *root;
    pseudo->left = NULL;

    struct Node *tail = pseudo;
    struct Node *rest = tail->right;
    int count = 0;

    while (rest) {
        if (rest->left) {
            Node *tmp = rest->left;
            rest->left = tmp->right;
            tmp->right = rest;
            rest = tmp;
            tail->right = tmp;
        } else {
            tail = rest;
            rest = rest->right;
            count++;
        }
    }
    *root = pseudo->right;
    free(pseudo);
    return count;
}


struct Node* compress(struct Node* root, int m) {
    struct Node* pseudo = malloc(sizeof(Node));
    pseudo->right = root;
    struct Node* scanner = pseudo;

    for (int i = 0; i < m; i++) {
        rotateLeft(scanner);
        scanner = scanner->right;
    }
    root = pseudo->right;
    free(pseudo);
    return root;
}

struct Node* vineToTree(Node *root, int count) {
    int full = (1 << (int)floor(log2(count + 1))) - 1;
    root = compress(root, count - full);
    for (int m = full / 2; m > 0; m /= 2) {
        root = compress(root, m);
    }
    return root;
}

struct Node* balanceTree(struct Node* head) {
    int n = treeToVine(&head);
    return vineToTree(head, n);
}

struct Node* generateTree(int numNodes){
    if(numNodes == 0 || numNodes > 10000000){
        printf("can only generate a tree in range 1 < numNodes < 10000000");
        return NULL;
    }
    srand((unsigned)time(NULL));
    struct Node* head = NULL;
    for(int i=0; i<numNodes; i++){
        int rval = rand() % numNodes;
        head = insertNode(head, rval);
    }
    return head;
}

void deleteTree(struct Node* head){
    if(head != NULL) {
        deleteTree(head->left);
        deleteTree(head->right);
        free(head);
    }
}