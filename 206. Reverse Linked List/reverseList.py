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
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        currentNode = head
        prevNode = None
        while(currentNode is not None):
            nextNode = currentNode.next
            currentNode.next = prevNode
            prevNode = currentNode
            currentNode = nextNode
        return prevNode
    def printLinkedList(self, head=None):
        currentNode = head
        print("[")
        while(currentNode is not None):
            print(str(currentNode.val) + ",")
            currentNode = currentNode.next
        print("]")        


# Intuition: We must reverse the list given the head which is a ListNode passed in. We can use three variables to track previous, current and next nodes. The head will automatically become the tail, so first we will grab a point to the next Node, and then set the next parameter to null. We will keep track of this node as the previous node. Moving on to the next Node, we will get the next Node again, and then set the next parameter and so on and so on. Eventually we will get to the end, see that there is no more nodes and then stop.

#Approach: We declare a variable currentNode that is set immediately to the input head. We declare another variable prevNode to store the previous node which will accept the pointer of the currentNode. Finally we have a third variable nextNode to track which is the next node to move onto. First we set prevNode to currentNode, currentNode to currentNode.next, nextNode equal to currentNode.next then we enter our loop, the condition of the loop will be while the currentNode is not equal to null. Set the previous node to currentNode, currentNode to NextNode, and currentNode.next to prevNode which is what actually reverses the linked list. Repeat the loop. Once the last node is read we break from the loop and return prevNode.

#Complexity: 
#-Time: It is a simple traversal that depends solely on the linked list size so $$O(n)$$
#-Space: The linked list is reversed in place, no extra space is required so $$O(n)$$ */


node5 = ListNode(5)
node4 = ListNode(4, node5)
node3 = ListNode(3, node4)
node2 = ListNode(2, node3)
node1 = ListNode(1, node2)

sol = Solution()

reversedList1 = sol.reverseList(node1)
print("Expected [5,4,3,2,1] got: ")
sol.printLinkedList(reversedList1)

node2.val = 2; node2.next = None
node1.val = 1; node1.next = node2

reversedList2 = sol.reverseList(node1)
print("Expected [2,1] got: ")
sol.printLinkedList(reversedList2)

node1 = None
reversedList3 = sol.reverseList(node1);
print("Expected [] got ")
sol.printLinkedList(reversedList3)
