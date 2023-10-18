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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
};

/* Intuition: We must merge the two lists given the heads. The fact that both lists are sorted in non-decreasing order helps, as a simple traversal will be sufficient. Recursion will be useful for this situation. 

Approach: The recursion stops and collapses back when when of the input lists is at the end, that is, when it is null. If it is not null, do a comparison between the two values of the current Node of the list, and then recursively call the function from that point to advance.

Complexity: 
-Time: It is a simple traversal of each list that depends solely on the linked list size so $$O(n+m)$$
-Space: The 2 linked lists are merged in place, no extra space is required so $$O(n+m)$$ */

void printMergedLists(struct ListNode* head) {
    ListNode* currentNode = head;
    cout << "[";
    while(currentNode != NULL) {
        cout << currentNode->val << ",";
        currentNode = currentNode->next;
    }
    cout << "]\n";
}

int main() {
    Solution sol;
    
    ListNode* node1c = new ListNode(4);
    ListNode* node1b = new ListNode(2, node1c);
    ListNode* node1a = new ListNode(1, node1b);
    
    ListNode* node2c = new ListNode(4);
    ListNode* node2b = new ListNode(3, node2c);
    ListNode* node2a = new ListNode(1, node2b);

    ListNode* mergedList1 = sol.mergeTwoLists(node1a, node2a);
    cout << "Expecting [1,1,2,3,4,4] got "; 
    printMergedLists(mergedList1);

    node1a = NULL;
    node2a = NULL;

    ListNode* mergedList2 = sol.mergeTwoLists(node1a, node2a);
    cout << "Expecting [] got ";
    printMergedLists(mergedList2);

    node1a = NULL;
    node2a = new ListNode(0);
    
    ListNode* mergedList3 = sol.mergeTwoLists(node1a, node2a);
    cout << "Expecting [0] got ";
    printMergedLists(mergedList3);

    node1a = new ListNode(1);
    node1a->val = 1; node1a->next = NULL;
    node2a->val = 1; node2a->next = NULL;

    ListNode* mergedList4 = sol.mergeTwoLists(node1a, node2a);
    cout << "Expecting [1,1] got ";
    printMergedLists(mergedList4);

    delete(node1c);
    delete(node1b);
    delete(node1a);
    delete(node2c);
    delete(node2b);
    delete(node2a);
}