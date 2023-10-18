/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}


/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */

/*** My initial solution, iterative approach and very brute force 
var mergeTwoLists = function(list1, list2) {
    // edge cases
    if(list1 == null && list2 == null) {
        return null;
    } 
    if(list1 != null && list2 == null) {
        return list1;
    } 
    if(list1 == null && list2 != null) {
        return list2;
    }
    let currentNode1 = list1;
    let currentNode2 = list2;
    // determines the head to start with, also set our runningNode to the head
    if(currentNode1.val > currentNode2.val) {
        head = currentNode2;
        currentNode2 = currentNode2.next;
    } else {
        head = currentNode1;
        currentNode1 = currentNode1.next;
    }
    let runningNode = head;
    let tempNode; // used to temporarily store a node as we rearrange links
    // loop while currentNode1 AND currentNode2 are not null
    while(currentNode1 && currentNode2 ) {
        if(currentNode2.val >= currentNode1.val) {
            tempNode = currentNode1.next;
            runningNode.next = currentNode1
            runningNode = currentNode1;
            currentNode1 = tempNode;
           
        } else {
            tempNode = currentNode2.next;
            runningNode.next = currentNode2;
            runningNode = currentNode2;
            currentNode2 = tempNode;
        } 
    }
    // while loop complete, at least one of the lists is at the end. now to restore the links to the list that still has values
    if(currentNode2 == null && currentNode1 != null) {
        runningNode.next = currentNode1;
    } else if (currentNode1 == null && currentNode2 != null) {
        runningNode.next = currentNode2;
    } 
    return head;
};
***/

/*** Much simpler internet version of the iterative approach 
var mergeTwoLists = function(list1, list2) {
       // initialize new linked list
       let head = new ListNode(null)

       // new pointer
       let current = head
   
       // loop while both lists are not null (did not reach end)
       while (list1 && list2) {
   
           // check which val is lower and point current to it
           // move the pointer on the lower list 
           if (list1.val <= list2.val){
               current.next = list1
               list1 = list1.next
           } else {
               current.next = list2
               list2 = list2.next
           }
   
           // move the current pointer
           current = current.next
       }
   
       // determine which node is not null
       let remaining = list1 || list2
   
       // set current to the remaining list
       current.next = remaining
   
   
       // return next because head was initialized to null
       return head.next
}
*** / 



/* Intuition: We must merge the two lists given the heads. The fact that both lists are sorted in non-decreasing order helps, as a simple traversal will be sufficient. Create new linked list. Use a pointer for the new linked list, list1 head, and list2 head. Loop while both lists are not null (has not reached the end). On each iteration, find the lower value and set it to the next current node, increment that lower value list. increment the new linked list each iteration. See notes in the code for better way to visualize.

Approach: Declare a new node to be the new Head. We will use a pointer called current to move each iteration through the loop. Create a while loop with the condition of both currentNode1 AND currentNode2 are not null. Next we do a comparison of the two currentNode's values. If the two node values are equal (or if node2 is higher), set the pointer next value to the lower node, then advance that node by 1, then set the pointer to the node just compared to. Once at least one of the lists is traversed, the loop will exit and we do a check to see which list still has remaining items, then we set the pointer to the remaining node in that list, which is still connected to the end. We then return the head of the new list.

Complexity: 
-Time: It is a simple traversal of each list that depends solely on the linked list size so $$O(n+m)$$
-Space: The 2 linked lists are merged in place, no extra space is required so $$O(n+m)$$ */



/** This is a recursive version found from the internet, see the image files in this folder to see a visual explanation, very compact! To solve this problem, we can use recursion, calling it until one of the sheets is null, and while it is not null, we do an equality check, if list1 is less than or equal to list2, we call recursion with list1.next = mergeTwoLists (list1.next, list2), else if the value is greater than list2.next = mergeTwoLists(list1, list2.next). If one of the sheets is null, we simply return the opposite list (we don't care if it's null or not). Thus, when the recursion ends, the stack will begin to collapse in reverse order, which will allow us to get a new merged sorted list.*/


var mergeTwoLists = function (l1, l2) {
    if (!l1) return l2;
    else if (!l2) return l1;
    else if (l1.val <= l2.val) {
        l1.next = mergeTwoLists(l1.next, l2);
        return l1;
    } else {
        l2.next = mergeTwoLists(l1, l2.next);
        return l2
    }
};









function printMergedLists(head) {
    let currentNode = head;
    const outputStack = [];
    while(currentNode != null) {
        outputStack.push(currentNode.val);
        currentNode = currentNode.next;
    }
    console.log(outputStack);
}


let node1c = new ListNode(4, null);
let node1b = new ListNode(2, node1c);
let node1a = new ListNode(1, node1b);

let node2c = new ListNode(4, null);
let node2b = new ListNode(3, node2c);
let node2a = new ListNode(1, node2b);

let mergedList1 = mergeTwoLists(node1a, node2a);
console.log("Expecting [1,1,2,3,4,4] got "); 
printMergedLists(mergedList1);

node1a = null;
node2a = null;

let mergedList2 = mergeTwoLists(node1a, node2a);
console.log("Expecting [] got ");
printMergedLists(mergedList2);

node1a = null;
node2a = new ListNode(0);

let mergedList3 = mergeTwoLists(node1a, node2a);
console.log("Expecting [0] got ");
printMergedLists(mergedList3);

