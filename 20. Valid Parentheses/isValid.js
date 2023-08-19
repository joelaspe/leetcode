/**
 * @param {string} s
 * @return {boolean}
 */
/*
var isValid = function(s) {
    //edge case: if input string is odd length it cannot be valid
    if(s.length % 2 === 1) {
        return false;
    }

    const recordArr = [];
    let poppedBracket;
    for(bracket of s) {
        // if it's an opening bracket, just push onto the record array
        if(bracket === '(' || bracket === '{' || bracket === '[') {
            recordArr.push(bracket);
        } else {
            // we know that bracket is a closing one, so get the most recent opening bracket from the record array
            poppedBracket = recordArr.pop(); 
            switch(bracket) {
                case ')': {
                    if(poppedBracket != '(') {
                        return false;
                    } 
                    break;
                }
                case '}': {
                    if(poppedBracket != '{') {
                        return false;
                    }
                    break;
                }
                case ']': {
                    if(poppedBracket != '[') {
                        return false;
                    }
                    break;
                }
            }
        }
    }
    return (recordArr.length === 0);
};
*/
/*Internet solution: Is more elegant because it uses an object as a hash table to determine what closing bracket is associated with each opening bracket */
var isValid = function(s) {
    //edge case: if input string is odd length it cannot be valid
    if(s.length % 2 === 1) {
        return false;
    }
    const pairs = {
        "(": ")",
        "[": "]",
        "{": "}"
    }
    const recordArr = [];
    for(let bracket of s) {
        // if it's an opening bracket, just push onto the record array
        if(bracket === '(' || bracket === '{' || bracket === '[') {
            recordArr.push(bracket);
        } else if(pairs[recordArr.pop()] !== bracket){
            // we know that bracket is a closing one, so get the most recent opening bracket from the record array
            return false;
        }
    }
    return (recordArr.length === 0);
};


/* Intuition: Given an input string that comprises only the characters '(', ')', '{', '}', '[' and ']' we are asked to determine if the input string is valid based on if the parentheses (bracket, curly or normal) are the appropriate type and in order. We need a way to store the opening bracket and the order each opening bracket appeared in. When we start seeing the closing brackets again, look at the most recent think added and see if it matches the expected. A stack structure would seem to work best for this purpose. 

Approach: Javascript arrays with pop and push function as a stack so we will declare an array to store the record of opening brackets. Begin iterating through the input string, and check if it is an opening bracket, if it is, push that character onto the record array. If instead a closing bracket is encountered, pop the last element from the array and compare it to the closing bracket (i.e. if we have ']' then '[' should have been popped, etc.) If at any time that comparison fails, return false. After iteration through the input string, do a final check of the length of the record array. If it has any elements remaining, return false because we didn't fully close out the opening brackets. Otherwise return true.

Complexity: 
-Time: We loop through the input array operations once so the time complexity is $$O(n)$$
-Space: The record array could be as large as the input array at the most, so space complexity is $$O(n)$$.  */


const s1 = "()";
const output1 = isValid(s1);
console.log("Test 1: Expecting true got " + output1);


const s2 = "()[]{}";
const output2 = isValid(s2);
console.log("Test 2: Expecting true got " + output2);

const s3 = "(]";
const output3 = isValid(s3);
console.log("Test 3: Expecting false got " + output3);

const s4 = "(((([[[[{{{{}}}}]]]]))))";
const output4 = isValid(s4);
console.log("Test 4: Expecting true got " + output4);

const s5 = "(()()(){}{}{}{}{{{{{}}]][}";
const output5 = isValid(s5);
console.log("Test 5: Expecting false got " + output5);

const s6 = "(";
const output6 = isValid(s6);
console.log("Test 6 (string input length 1): Expecting false got " + output6);

const s7 = "((";
const output7 = isValid(s7);
console.log("Test 7: Expecting false got " + output7);

const s8 = ")";
const output8 = isValid(s8);
console.log("Test 8: Expecting false got " + output8);