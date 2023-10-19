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
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if(list1 == null) {
            return list2;
        }
        if(list2 == null) {
            return list1;
        }
        if(list1.val < list2.val) {
            list1.next = mergeTwoLists(list1.next, list2);
            return list1;
        } else {
            list2.next = mergeTwoLists(list1, list2.next);
            return list2;
        }
    }
    public void printMergedLists(ListNode head) {
        ListNode currentNode = head;
        System.out.print("[");
        while(currentNode != null) {
            System.out.print(currentNode.val + ",");
            currentNode = currentNode.next;
        }
        System.out.println("]");
    }

    public static void main(String args[]) {
        Solution sol = new Solution();
    
        Solution.ListNode node1c = sol.new ListNode(4);
        Solution.ListNode node1b = sol.new ListNode(2, node1c);
        Solution.ListNode node1a = sol.new ListNode(1, node1b);
        
        Solution.ListNode node2c = sol.new ListNode(4);
        Solution.ListNode node2b = sol.new ListNode(3, node2c);
        Solution.ListNode node2a = sol.new ListNode(1, node2b);
    
        Solution.ListNode mergedList1 = sol.mergeTwoLists(node1a, node2a);
        System.out.print("Expecting [1,1,2,3,4,4] got "); 
        sol.printMergedLists(mergedList1);
    
        node1a = null;
        node2a = null;
    
        Solution.ListNode mergedList2 = sol.mergeTwoLists(node1a, node2a);
        System.out.print("Expecting [] got ");
        sol.printMergedLists(mergedList2);
    
        node1a = null;
        node2a = sol.new ListNode(0);
        
        Solution.ListNode mergedList3 = sol.mergeTwoLists(node1a, node2a);
        System.out.print("Expecting [0] got ");
        sol.printMergedLists(mergedList3);
    
        node1a = sol.new ListNode(1);
        node2a.val = 1; node2a.next = null;
    
        ListNode mergedList4 = sol.mergeTwoLists(node1a, node2a);
        System.out.print("Expecting [1,1] got ");
        sol.printMergedLists(mergedList4);
    
    }

}

/* Intuition: We must merge the two lists given the heads. The fact that both lists are sorted in non-decreasing order helps, as a simple traversal will be sufficient. Recursion will be useful for this situation. 

Approach: The recursion stops and collapses back when when of the input lists is at the end, that is, when it is null. If it is not null, do a comparison between the two values of the current Node of the list, and then recursively call the function from that point to advance.

Complexity: 
-Time: It is a simple traversal of each list that depends solely on the linked list size so $$O(n+m)$$
-Space: The 2 linked lists are merged in place, no extra space is required so $$O(n+m)$$ */