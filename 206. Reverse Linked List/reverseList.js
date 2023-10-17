/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */

/* My initial working answer
var reverseList = function(head) {
    // edge case if number of nodes is 0 or 1  (returns null for 0 and head for 1)
    if(head == null || head.next == null) {
        return head;
    }
    let prevNode;
    let currentNode = head;
    let nextNode = head.next;
    while(nextNode != null) {
        prevNode = currentNode;
        // edge case, when prevNode is the first node (head) then set the next pointer to null to signify the end of the linked list
        if(prevNode == head) {
            prevNode.next = null;
        }
        currentNode = nextNode;
        nextNode = currentNode.next;
        // reverse the link
        currentNode.next = prevNode;

    }
    return currentNode;
}; */

/** Internet version, more simplified ***/
var reverseList = function(head) {
    let [prev,current] = [null,head]
    // let prev = null;
    // let current = head;
    while(current != null){
        let future = current.next;
        current.next = prev;
        prev = current;
        current = future
    }
    return prev;
};



/* Intuition: We must reverse the list given the head which is a ListNode passed in. The head will automatically become the tail, so first we will grab a point to the next Node, and then set the next parameter to null. We will keep track of this node as the previous node. Moving on to the next Node, we will get the next Node again, and then set the next parameter and so on and so on. Eventually we will get to the end, see that there is no more nodes and then stop.

Approach: First we will check for the edge case, when the number of nodes is 0 which is a check for null, and we also check for an edge case of number of nodes 1, which is a check for the next pointer is null. Next, we declare a variable currentNode that is set immediately to the input head. We declare another variable prevNode to store the previous node which will accept the pointer of the currentNode. Finally we have a third variable nextNode to track which is the next node to move onto. First we set prevNode to currentNode, currentNode to currentNode.next, nextNode equal to currentNode.next then we enter our loop, the condition of the loop will be while the nextNode is not equal to null. Set the previous node to currentNode, currentNode to NextNode, and currentNode.next to prevNode which is what actually reverses the linked list. Repeat the loop. Once the last node is read we break from the loop and return currentNode.

Complexity: 
-Time: It is a simple traversal that depends solely on the linked list size so $$O(n)$$
-Space: The linked list is reversed in place, no extra space is required so $$O(n)$$ */

function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val);
    this.next = (next===undefined ? null : next);
}

function printLinkedList(head) {
    let currentNode = head;
    const printArray = [];
    while(currentNode != null) {
        printArray.push(currentNode.val);
        currentNode = currentNode.next;
    }
    console.log(printArray);
}


let node1, node2, node3, node4, node5;
node5 = new ListNode(5, null);
node4 = new ListNode(4, node5);
node3 = new ListNode(3, node4);
node2 = new ListNode(2, node3);
node1 = new ListNode(1, node2);

const reversedList1 = reverseList(node1);
console.log("Expected [5,4,3,2,1] got: "); 
printLinkedList(reversedList1);

node2 = new ListNode(2, null);
node1 = new ListNode(1, node2);

const reversedList2 = reverseList(node1);
console.log("Expected [2,1] got: ");
printLinkedList(reversedList2);

node1 = null;
const reversedList3 = reverseList(node1);
console.log("Expected [] got ");
printLinkedList(reversedList3);