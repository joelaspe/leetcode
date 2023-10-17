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

