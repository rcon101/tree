#include <stdio.h>
#include <time.h>
#include "tree.h"

int main(int argc, char** argv) {
    printf("main.c running...\n");
    int nums[] = {2, 1, 5, 7, 8, 4, 3, 9, 0, 6};
    int n = sizeof(nums) / sizeof(nums[0]);
    struct Node* head = NULL;
    for(int i=0; i<n; i++) {
        head = insertNode(head, nums[i]);
    }
    printf("Printing inOrder...\n");
    printInOrder(head);
    printf("Printing postOrder...\n");
    printPostOrder(head);
    printf("Printing preOrder...\n");
    printPreOrder(head);
    printf("Printing reverseInOrder...\n");
    printReverseInOrder(head);
    printf("Printing reversePostOrder...\n");
    printReversePostOrder(head);
    printf("Printing reversePreOrder...\n");
    printReversePreOrder(head);

    printf("Number of Nodes: %d\n", numNodes(head));

    struct Node* subtree_a = getSubtree(head, 5);
    printf("Subtree A (%d nodes): \n", numNodes(subtree_a));
    printTree(subtree_a, 0);

    struct Node* rtree = generateTree(1000);
    printTree(rtree,0);

    deleteTree(head);
    return 0;
}