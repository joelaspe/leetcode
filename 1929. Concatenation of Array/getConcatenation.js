/**
 * @param {number[]} nums
 * @return {number[]}
 */
/*
var getConcatenation = function(nums) {
    let ans = [];
    for(let i = 0; i < nums.length * 2; i++) {
        ans.push(nums[i % nums.length]);
    }
    return ans;
};
*/

/*** Internet version, does not use Array methods */
var getConcatenation = function(nums) {
    let ans = [];
    for(let i = 0; i < nums.length * 2; i++) {
        ans[i] = nums[i % nums.length];
    }
    return ans;
};

/* 
Intuition: I'm seeing a lot of solutions that just add onto the input array using push and then returning the input array. The problem wants us to concatenate the input array with itself, effectively returning a new array that is twice as long as the original. The input array should not be modified. We can start by iterating through the array and add onto the end of the array. We will do this twice so the loop size will be twice the size of the input array. We will use the modulo operator to only have to use one loop.

Approach: Create a new empty array `ans`. Begin by iterating through the array `nums`. On each iterator `i` add the current element onto the end of `ans`. We use the modulo operator `%` which will come into effect once i is greater than input length. Once the iteration is complete, return `ans`.

Time Complexity: We are copying the array twice so total is $$O(2n)$$ -> $$O(n)$$.

Space complexity: We are creating a whole new copy of the array then doubling it in size, so space used is $$O(2n)$$->$$O(n)$$.

*/

let array1 = [1,2,1];
const output1 = getConcatenation(array1);
console.log(`Expecting [1,2,1,1,2,1] got ${output1}`);

let array2 = [1,3,2,1];
const output2 = getConcatenation(array2);
console.log(`Expecting [1,3,2,1,1,3,2,1] got ${output2}`);

let array3 = [9];
const output3 = getConcatenation(array3);
console.log(`Expecting [9,9] got ${output3}`);

