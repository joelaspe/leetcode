/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
       
   // because the array is non-descending we know the first element is the beginning of our ascent up, and will never be modified
   let currentNum = nums[0]; 
   let indexCurrentNum = 0;
   let uniqueElements = 1;
   // loop through the array
   for(let i = 1; i < nums.length; i++) {
        // compare the current element to current max number, then update current max number and update the index of current number by one, and insert the value of the current element into that index. Update the number of unique elements by one
        if(nums[i] > currentNum) {
            indexCurrentNum++;
            uniqueElements++;
            currentNum = nums[i];
            nums[indexCurrentNum] = nums[i];
        }
   }
   return uniqueElements;
};

/* Complexity:
    Time Complexity: Since we only traverse the array once, the time complexity is O(n)
    Space complexity: The algorithm uses constant extra space, so O(1)
*/

let array1 = [1,1,2];
const output1 = removeDuplicates(array1);
console.log(`array 1 should be [1,2,_] and it is actually ${array1}`); 
console.log(`output1 should be 2, it is actually ${output1}`);

let array2 = [0,0,1,1,1,2,2,3,3,4];
const output2 = removeDuplicates(array2);
console.log(`array 2 should be [0,1,2,3,4,_,_,_,_,_,_] and it is actually ${array2}`);
console.log(`output 2 should be 5 it is actually ${output2}`);

let array3 = [-10,-9,-9,-5,0,2,2,2,3,5];
const output3 = removeDuplicates(array3);
console.log(`array 3 should be [-10,-9,-5,0,2,3,5,_,_,_] and it is actually ${array3}`);
console.log(`output 3 should be 7 it is actually ${output3}`);
console.log(output3); //=> ;

const array4 = [1];
const output4 = removeDuplicates(array4);
console.log(`array 4 should be [1] and it is actually ${array4}`);
console.log(`output 4 should be 1 it is actually ${output4}`);

