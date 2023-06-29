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

The problem requies us to remove elements from the array that match a given input. We will leave anything in the array that does not conform to the input val. Additionally when an element is removed due to matching the input val, the space it filled is to be filled with something else that is valid. 

Approach:

We can use two pointers i and j, where i points to the current element being looked at and also is used as the tracker for the number of elements that do not equal to val (actually i + 1). j will start at the end of the array. Start by looking at nums[i], if it matches val, then look at nums[j]. If nums[j] also matches val, then move j to the left by one. Then do the comparison again. Once a nums[j] is found that is acceptable (not equal to val) then set nums[i] = nums[j] then increment (move to the right) i by one. Do this until we reach j = nums.length

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
