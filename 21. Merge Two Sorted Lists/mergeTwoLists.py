# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None:
            return list2
        if list2 is None:
            return list1
        if list1.val < list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2

#/* Intuition: We must merge the two lists given the heads. The fact that both lists are sorted in non-decreasing order helps, as a simple traversal will be sufficient. Recursion will be useful for this situation. 

#Approach: The recursion stops and collapses back when when of the input lists is at the end, that is, when it is null. If it is not null, do a comparison between the two values of the current Node of the list, and then recursively call the function from that point to advance.

#Complexity: 
#-Time: It is a simple traversal of each list that depends solely on the linked list size so $$O(n+m)$$
#-Space: The 2 linked lists are merged in place, no extra space is required so $$O(n+m)$$ */

def printMergedLists(head):
    currentNode = head
    print("[")
    while currentNode is not None:
        print(str(currentNode.val) + ",")
        currentNode = currentNode.next
    print("]")


sol = Solution()

node1c = ListNode(4)
node1b = ListNode(2, node1c)
node1a = ListNode(1, node1b)

node2c = ListNode(4)
node2b = ListNode(3, node2c)
node2a = ListNode(1, node2b)
    
mergedList1 = sol.mergeTwoLists(node1a, node2a)
print("Expecting [1,1,2,3,4,4] got ")
printMergedLists(mergedList1)
    
node1a = None
node2a = None
    
mergedList2 = sol.mergeTwoLists(node1a, node2a)
print("Expecting [] got ")
printMergedLists(mergedList2)


node1a = None
node2a = ListNode(0)
        
mergedList3 = sol.mergeTwoLists(node1a, node2a)
print("Expecting [0] got ")
printMergedLists(mergedList3)
   
node1a = ListNode(1)
node2a.val = 1
node2a.next = None
    
mergedList4 = sol.mergeTwoLists(node1a, node2a)
print("Expecting [1,1] got ")
printMergedLists(mergedList4)