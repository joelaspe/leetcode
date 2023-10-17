/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prevNode = nullptr;
        ListNode *currentNode = head;
        ListNode *nextNode;
        while(currentNode != nullptr) {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        return prevNode;
    }
};


/* Intuition: We must reverse the list given the head which is a ListNode passed in. We can use three variables to track previous, current and next nodes. The head will automatically become the tail, so first we will grab a point to the next Node, and then set the next parameter to null. We will keep track of this node as the previous node. Moving on to the next Node, we will get the next Node again, and then set the next parameter and so on and so on. Eventually we will get to the end, see that there is no more nodes and then stop.

Approach: We declare a variable currentNode that is set immediately to the input head. We declare another variable prevNode to store the previous node which will accept the pointer of the currentNode. Finally we have a third variable nextNode to track which is the next node to move onto. First we set prevNode to currentNode, currentNode to currentNode.next, nextNode equal to currentNode.next then we enter our loop, the condition of the loop will be while the currentNode is not equal to null. Set the previous node to currentNode, currentNode to NextNode, and currentNode.next to prevNode which is what actually reverses the linked list. Repeat the loop. Once the last node is read we break from the loop and return prevNode.

Complexity: 
-Time: It is a simple traversal that depends solely on the linked list size so $$O(n)$$
-Space: The linked list is reversed in place, no extra space is required so $$O(n)$$ */

/*** Alternative approach using Recursion from the internet
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* h2 = reverseList(head->next);
        head->next->next = head;
        head->next=prev;
        return h2;
    }

};
*/

void printLinkedList(ListNode* head) {
    cout << "[";
    ListNode *current = head;
    while(current != nullptr) {
        cout << current->val << ",";
        current = current->next;
    }
    cout << "]\n";
}


int main() {
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);
    
    Solution sol;
    ListNode* reversedList1 = sol.reverseList(node1);
    cout << "Expected [5,4,3,2,1] got: "; 
    printLinkedList(reversedList1);

    node2->val = 2; node2->next = NULL;
    node1->val = 1; node1->next = node2;

    ListNode* reversedList2 = sol.reverseList(node1);
    cout << "Expected [2,1] got: ";
    printLinkedList(reversedList2);

    node1 = nullptr;
    ListNode* reversedList3 = sol.reverseList(node1);
    cout << "Expected [] got ";
    printLinkedList(reversedList3);

    delete(node5);
    delete(node4);
    delete(node3);
    delete(node2);
    delete(node1);

}