#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node*));
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

int numNodes(struct Node* head) {
    if(head==NULL) return 0;
    return 1 + numNodes(head->left) + numNodes(head->right);
}

struct Node* getSubtree(struct Node* head, int value) {
    if(head==NULL || head->value == value) return head;
    if(value < head->value) return getSubtree(head->left, value);
    else if(value > head->value) return getSubtree(head->right, value);
    else return NULL;
}

void deleteTree(struct Node* head){
    if(head != NULL) {
        deleteTree(head->left);
        deleteTree(head->right);
        free(head);
    }
}