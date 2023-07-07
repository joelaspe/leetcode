#include <stdlib.h>
#include <stdio.h>

int calPoints(char ** operations, int operationsSize){
    int* scoreArray = (int*) malloc(operationsSize * sizeof(int));
    //scoreArrayLength is used to track how many elements we've added to the array because c does not have a built in array.length feature like javascript/java etc
    int scoreArrayLength = 0;
    for(int i = 0 ; i < operationsSize; i++) {
        switch(*operations[i]) {
            case '+': 
                scoreArray[scoreArrayLength] = scoreArray[scoreArrayLength - 2] + scoreArray[scoreArrayLength - 1];
                scoreArrayLength++;
                break;
            case 'C':
                scoreArray[scoreArrayLength] = 0;
                scoreArrayLength--;
                break;
            case 'D':
                scoreArray[scoreArrayLength] = scoreArray[scoreArrayLength - 1] * 2;
                scoreArrayLength++;
                break;
            default: 
                scoreArray[scoreArrayLength] = strtol(operations[i], NULL, 10);
                scoreArrayLength++;
        }
    }
    int sum = 0;
    for(int i = 0; i < scoreArrayLength; i++) {
        sum += scoreArray[i];
    }
    free(scoreArray);
    return sum;
}


/* Intuition: The problem wants us to create a record that is empty at the beginning of the game. We will store this in an array of numbers []. We will iterate through the input array and on each element check what the operation is. Since the constraints are that there will be at least 2 elements for a + operation and at least 1 element for both C and D operation, we will not have to worry about edge cases. The operations that occur will always deal with the last element of our score array so pop() and push() like operations will be sufficient. At the end, add up the scores and return them.

Approach: Declare a array `scoreArray`. Loop through the input `ops` and using a switch block look at each element to determine the operation to perform. 
If `+`, we will add `scoreArray[scorearray.length-2] + scoreArray[scoreArray.length-1]` and add it to the end of the `scoreArray`. If `C`, we will remove the last element in `scoreArray[i]`; If `D` we will take the previous score in `scoreArray[scoreArray.length-1]` and double it, adding it to the end of the array `scoreArray`. If it's anything else it is guaranteed to be a string representing an integer from the range -3*10^4 to 3*10^4. Add this number to the end of the scoreArray. When the loop iteration is complete, loop through the scoreArray and add it up, then return the final number. Note: All string numbers will need to be convered to integer first. 

Complexity: 
-Time: We loop through the input array operations once, and the score array once which can have a maximum size of n so time complexity is $$O(2n)$$ -> $$O(n)$$
-Space: The score array could be as large as the input array at the most, so space complexity is $$O(n)$$.  */

int main() {
    char* array1[5] = {"5", "2", "C", "D", "+"};
    int output1 = calPoints(array1, 5);
    printf("Expecting 30 got %d\n", output1);

    char* array2[] = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    int output2 = calPoints(array2, 8);
    printf("Expecting 27 got %d\n", output2);

    char* array3[] = {"1", "C"};
    int output3 = calPoints(array3, 2);
    printf("Expecting 0 got %d\n", output3);
}

