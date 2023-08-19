#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool isValid(char * s){
    //edge case: If input array is odd length, automatically return false
    if(strlen(s) % 2 == 1) {
        return false;
    }
    char recordArray[strlen(s)]; // maximum size of record array is the length of the input string
    int arrPosTracker = -1;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            arrPosTracker++;
            recordArray[arrPosTracker] = s[i];
        }
        else {
            if(arrPosTracker == -1) {
                return false;
            }
            switch(s[i]) {
                case ')': {
                    if(recordArray[arrPosTracker] != '(') {
                        return false;
                    }
                    arrPosTracker--;
                    break;
                }
                case ']': {
                    if(recordArray[arrPosTracker] != '[') {
                        return false;
                    }
                    arrPosTracker--;
                    break;
                }
                case '}': {
                    if(recordArray[arrPosTracker] != '{') {
                        return false;
                    }
                    arrPosTracker--;
                    break;
                }
            }
        }
    }
    return (arrPosTracker == -1);
}

void main() {
    char *s1 = "()";
    bool output1 = isValid(s1);
    printf("Test 1: Expecting true (1) got %d\n", output1);


    char *s2 = "()[]{}";
    bool output2 = isValid(s2);
    printf("Test 2: Expecting true (1) got %d\n", output2);

    char *s3 = "(]";
    bool output3 = isValid(s3);
    printf("Test 3: Expecting false (0) got %d\n", output3);

    char *s4 = "(((([[[[{{{{}}}}]]]]))))";
    bool output4 = isValid(s4);
    printf("Test 4: Expecting true (1) got %d\n", output4);

    char *s5 = "(()()(){}{}{}{}{{{{{}}]][}";
    bool output5 = isValid(s5);
    printf("Test 5: Expecting false (0) got %d\n", output5);

    char *s6 = "(";
    bool output6 = isValid(s6);
    printf("Test 6 (string input length 1): Expecting false (0) got %d\n", output6);

    char *s7 = "((";
    bool output7 = isValid(s7);
    printf("Test 7: Expecting false (0) got %d\n", output7);

    char *s8 = ")";
    bool output8 = isValid(s8);
    printf("Test 8: Expecting false (0) got %d\n", output8);

    char *s9 = "){";
    bool output9 = isValid(s9);
    printf("Test 9: Expecting false (0) got %d\n", output9);
}

/* Intuition: Given an input string that comprises only the characters '(', ')', '{', '}', '[' and ']' we are asked to determine if the input string is valid based on if the parentheses (bracket, curly or normal) are the appropriate type and in order. We need a way to store the opening bracket and the order each opening bracket appeared in. When we start seeing the closing brackets again, look at the most recent think added and see if it matches the expected. A stack structure would seem to work best for this purpose. 

Approach:  Declare an array to store the record of opening brackets. C does not have a built in stack (like javascript arrays) so we will have to be a little more clever. We can use an index tracker to determine where on the stored record array we are currently at. Begin iterating through the input string, and check if it is an opening bracket, if it is, add that character into the next part of the recordArray. If instead a closing bracket is encountered, we compare the last added bracket in the recordArray and compare it to the closing bracket (i.e. if we have ']' then '[' should be on record) If at any time that comparison fails, return false. After iteration through the input string, do a final check of the tracker index, it should be at 0. If it is not, return false because we didn't fully close out the opening brackets. Otherwise return true.

Complexity: 
-Time: We loop through the input array operations once so the time complexity is $$O(n)$$
-Space: The record array could be as large as the input array at the most, so space complexity is $$O(n)$$.  */

