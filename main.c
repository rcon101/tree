#include <stdio.h>
#include "tree.h"

int main(int argc, char** argv) {
    printf("main.c running...\n");
    int nums[] = {2, 1, 5, 7, 8, 4, 3, 9, 0, 6};
    int n = sizeof(nums) / sizeof(nums[0]);
    struct Node* head = NULL;
    for(int i=0; i<n; i++) {
        head = insertNode(head, nums[i]);
    }
    printInOrder(head);
    deleteTree(head);
    return 0;
}