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
void deleteTree(struct Node* head){
    if(head != NULL) {
        deleteTree(head->left);
        deleteTree(head->right);
        free(head);
    }
}