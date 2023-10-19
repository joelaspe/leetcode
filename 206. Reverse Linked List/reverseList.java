/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */


 class Solution {
    
    public class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
    }
    public ListNode reverseList(ListNode head) {
        ListNode prevNode = null;
        ListNode currentNode = head;
        ListNode nextNode;
        while(currentNode != null) {
            nextNode = currentNode.next;
            currentNode.next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }
        return prevNode;
    }

    public static void printLinkedList(ListNode head) {
        ListNode currentNode = head;
        System.out.print("[");
        while(currentNode != null) {
            System.out.print(currentNode.val + ",");
            currentNode = currentNode.next;
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        Solution.ListNode node5 = sol.new ListNode(5);
        Solution.ListNode node4 = sol.new ListNode(4, node5);
        Solution.ListNode node3 = sol.new ListNode(3, node4);
        Solution.ListNode node2 = sol.new ListNode(2, node3);
        Solution.ListNode node1 = sol.new ListNode(1, node2);
        
        Solution.ListNode reversedList1 = sol.reverseList(node1);
        System.out.println("Expected [5,4,3,2,1] got: "); 
        printLinkedList(reversedList1);

        node2.val = 2; node2.next = null;
        node1.val = 1; node1.next = node2;

        Solution.ListNode reversedList2 = sol.reverseList(node1);
        System.out.println("Expected [2,1] got: ");
        printLinkedList(reversedList2);

        node1 = null;
        Solution.ListNode reversedList3 = sol.reverseList(node1);
        System.out.println("Expected [] got ");
        printLinkedList(reversedList3);

    }
}

/* Intuition: We must reverse the list given the head which is a ListNode passed in. We can use three variables to track previous, current and next nodes. The head will automatically become the tail, so first we will grab a point to the next Node, and then set the next parameter to null. We will keep track of this node as the previous node. Moving on to the next Node, we will get the next Node again, and then set the next parameter and so on and so on. Eventually we will get to the end, see that there is no more nodes and then stop.

Approach: We declare a variable currentNode that is set immediately to the input head. We declare another variable prevNode to store the previous node which will accept the pointer of the currentNode. Finally we have a third variable nextNode to track which is the next node to move onto. First we set prevNode to currentNode, currentNode to currentNode.next, nextNode equal to currentNode.next then we enter our loop, the condition of the loop will be while the currentNode is not equal to null. Set the previous node to currentNode, currentNode to NextNode, and currentNode.next to prevNode which is what actually reverses the linked list. Repeat the loop. Once the last node is read we break from the loop and return prevNode.

Complexity: 
-Time: It is a simple traversal that depends solely on the linked list size so $$O(n)$$
-Space: The linked list is reversed in place, no extra space is required so $$O(n)$$ */
