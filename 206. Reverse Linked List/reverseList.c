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

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prevNode = NULL;
    struct ListNode* currentNode = head;
    struct ListNode* nextNode;
    while(currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;

    }
    return prevNode;
}


/* Intuition: We must reverse the list given the head which is a ListNode passed in. We can use three variables to track previous, current and next nodes. The head will automatically become the tail, so first we will grab a point to the next Node, and then set the next parameter to null. We will keep track of this node as the previous node. Moving on to the next Node, we will get the next Node again, and then set the next parameter and so on and so on. Eventually we will get to the end, see that there is no more nodes and then stop.

Approach: We declare a variable currentNode that is set immediately to the input head. We declare another variable prevNode to store the previous node which will accept the pointer of the currentNode. Finally we have a third variable nextNode to track which is the next node to move onto. First we set prevNode to currentNode, currentNode to currentNode.next, nextNode equal to currentNode.next then we enter our loop, the condition of the loop will be while the currentNode is not equal to null. Set the previous node to currentNode, currentNode to NextNode, and currentNode.next to prevNode which is what actually reverses the linked list. Repeat the loop. Once the last node is read we break from the loop and return prevNode.

Complexity: 
-Time: It is a simple traversal that depends solely on the linked list size so $$O(n)$$
-Space: The linked list is reversed in place, no extra space is required so $$O(n)$$ */

void printLinkedList(struct ListNode* head) {
    printf("[");
    struct ListNode *current = head;
    while(current != NULL) {
        printf("%d,", current->val);
        current = current->next;
    }
    printf("]\n");
}


int main() {
    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node5->val = 5; node5->next = NULL;
    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode*));
    node4->val = 4; node4->next = node5;
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node3->val = 3; node3->next = node4;
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node2->val = 2; node2->next = node3;
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    node1->val = 1; node1->next = node2;
    struct ListNode* reversedList1 = reverseList(node1);
    printf("Expected [5,4,3,2,1] got: "); 
    printLinkedList(reversedList1);

    node2->val = 2; node2->next = NULL;
    node1->val = 1; node1->next = node2;

    struct ListNode* reversedList2 = reverseList(node1);
    printf("Expected [2,1] got: ");
    printLinkedList(reversedList2);

    node1 = NULL;
    struct ListNode* reversedList3 = reverseList(node1);
    printf("Expected [] got ");
    printLinkedList(reversedList3);

    free(node5);
    free(node4);
    free(node3);
    free(node2);
    free(node1);
}