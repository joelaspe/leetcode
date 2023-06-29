/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */

var removeElement = function(nums, val) {
    let j = nums.length-1;
    for(let i = 0; i <= j; i++) {
        if(nums[i] === val) {
            nums[i] = nums[j];
            nums[j] = undefined;
            i--;
            j--;
        }
    }
    // return the position of j + 1 which is the number of times that no match to val was found
    return j + 1;
}; 

/* Intuition:

The intuition behind this solution is to iterate through the array and keep track of two pointers i and j. Each pointer will be put at opposite ends of the array. We will iterate through the array from left to right using i as the iterator. If the value at i matches the target value, then we will put the value at j into that position, then we effective "remove" the target value by removing the value at j. This is an indirect way of viewing the removal. Finally decrement both counters and go back through the loop again. We decrement i in this case because it is possible that the next value at j could match the value again. Stop the incrementing when j < i. Return j + 1 as the number of non-matching values.

Approach:

1. Initialize `j` to be `nums.length-1`.
2. Iterate through each element of the input array using the `i` pointer.
3. For each element `num[i]` check if it is equal to the target value.
- If `nums[i]` is equal to `val`, it is a target element
  -Set `nums[i]` equal to `nums[j]` to store the non-target element at the target element
  -Decrement `j` by one
  -Decrement `i` by one
4. Continue this process until j is less than i.
5. Return j + 1, as this will represent the total number of non-target elements


Complexity:
    Time Complexity: Since we only traverse the array once, the time complexity is O(n)
    Space complexity: The algorithm uses constant extra space, so O(1)

*/

let array1 = [3,2,2,3];
let val1 = 3;
const output1 = removeElement(array1, val1);
console.log(`array1 should be [2,2,_,_] it is actually ${array1}`);
console.log(`output1 should be 2, it is actually ${output1}`);

let array2 = [0,1,2,2,3,0,4,2];
let val2 = 2;
const output2 = removeElement(array2, val2);
console.log(`array2 should be [0,1,4,0,3,_,_,_] it is actually ${array2}`);
console.log(`output2 should be 5, it is actually ${output2}`);

let array3 = [1];
let val3 = 2;
const output3 = removeElement(array3, val3);
console.log(`array3 should be [1] it is actually ${array3}`);
console.log(`output3 should be 1 it is actually ${output3}`);

let array4 = [1];
let val4 = 1;
const output4 = removeElement(array4, val4);
console.log(`array4 should be [] it is actually ${array4}`);
console.log(`output4 should be 0 it is actually ${output4}`);

let array5 = [];
let val5 = 0;
const output5 = removeElement(array5, val5);
console.log(`array5 should be [] it is actually ${array5}`);
console.log(`output5 should be 0 it is actually ${output5}`);

let array6 = [3,3];
let val6 = 3;
const output6 = removeElement(array6, val6);
console.log(`array6 should be [] it is actually ${array6}`);
console.log(`output6 should be 0 it is actually ${output6}`);

let array7 = [4,5];
let val7 = 4;
const output7 = removeElement(array7, val7);
console.log(`array7 should be [5] it is actually ${array7}`);
console.log(`output7 should be 1 it is actually ${output7}`);

let array8 = [4,5];
let val8 = 5;
const output8 = removeElement(array8, val8);
console.log(`array8 should be [4] it is actually ${array8}`);
console.log(`output8 should be 1, it is actually ${output8}`);
