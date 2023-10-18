/* Intuition: We must merge the two lists given the heads. The fact that both lists are sorted in non-decreasing order helps, as a simple traversal will be sufficient. Recursion will be useful for this situation. 

Approach: The recursion stops and collapses back when when of the input lists is at the end, that is, when it is null. If it is not null, do a comparison between the two values of the current Node of the list, and then recursively call the function from that point to advance.

Complexity: 
-Time: It is a simple traversal of each list that depends solely on the linked list size so $$O(n+m)$$
-Space: The 2 linked lists are merged in place, no extra space is required so $$O(n+m)$$ */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int stopme = 0;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    if(list1 == NULL) {
        return list2;
    }
    if(list2 == NULL) {
        return list1;
    }
    if(list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;

    } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

void printMergedLists(struct ListNode* head) {
    struct ListNode* currentNode = head;
    printf("[");
    while(currentNode != NULL) {
        printf("%d,", currentNode->val);
        currentNode = currentNode->next;
    }
    printf("]\n");
}

int main() {

    struct ListNode* node1c = (struct ListNode*)malloc(sizeof(struct ListNode));
    node1c->val = 4; node1c->next = NULL;
    struct ListNode* node1b = (struct ListNode*)malloc(sizeof(struct ListNode));
    node1b->val = 2; node1b->next = node1c;
    struct ListNode* node1a = (struct ListNode*)malloc(sizeof(struct ListNode));
    node1a->val = 1; node1a->next = node1b;

    struct ListNode* node2c = (struct ListNode*)malloc(sizeof(struct ListNode));
    node2c->val = 4; node2c->next = NULL;
    struct ListNode* node2b = (struct ListNode*)malloc(sizeof(struct ListNode));
    node2b->val = 3; node2b->next = node2c;
    struct ListNode* node2a = (struct ListNode*)malloc(sizeof(struct ListNode));
    node2a->val = 1; node2a->next = node2b;

    struct ListNode* mergedList1 = mergeTwoLists(node1a, node2a);
    printf("Expecting [1,1,2,3,4,4] got "); 
    printMergedLists(mergedList1);

    node1a = NULL;
    node2a = NULL;

    struct ListNode* mergedList2 = mergeTwoLists(node1a, node2a);
    printf("Expecting [] got ");
    printMergedLists(mergedList2);

    node1a = NULL;
    node2a = (struct ListNode*)malloc(sizeof(struct ListNode));
    node2a->val = 0; node2a->next = NULL;

    struct ListNode* mergedList3 = mergeTwoLists(node1a, node2a);
    printf("Expecting [0] got ");
    printMergedLists(mergedList3);

    node1a = (struct ListNode*)malloc(sizeof(struct ListNode));
    node1a->val = 1; node1a->next = NULL;
    node2a->val = 1; node2a->next = NULL;

    struct ListNode* mergedList4 = mergeTwoLists(node1a, node2a);
    printf("Expecting [1,1] got ");
    printMergedLists(mergedList4);

    free(node1c);
    free(node1b);
    free(node1a);
    free(node2c);
    free(node2b);
    free(node2a);

}
