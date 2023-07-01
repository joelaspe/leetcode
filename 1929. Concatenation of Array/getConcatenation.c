#include <stdlib.h>
#include <stdio.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){

    *returnSize = 2 * numsSize;
    printf("returnSize is %d\n", *returnSize);
    int *ans = (int*)malloc(numsSize * 2 * sizeof(int));
    // if dynamic allocation failed exit the program
    if(ans == NULL) {
        printf("Memory allocation failed");
        exit(1);
    }
    for(int i = 0; i < *returnSize; i++) {
        ans[i] = nums[i % numsSize];
    }
    return ans;
}

/* 
Intuition: I'm seeing a lot of solutions that just add onto the input array using push and then returning the input array. The problem wants us to concatenate the input array with itself, effectively returning a new array that is twice as long as the original. The input array should not be modified. We can start by iterating through the array and add onto the end of the array. We will do this twice so the loop size will be twice the size of the input array. We will use the modulo operator to only have to use one loop.

Approach: Create a new empty array `ans`. Begin by iterating through the array `nums`. On each iterator `i` add the current element onto the end of `ans`. We use the modulo operator `%` which will come into effect once i is greater than input length. Once the iteration is complete, return `ans`.

Time Complexity: We are copying the array twice so total is $$O(2n)$$ -> $$O(n)$$.

Space complexity: We are creating a whole new copy of the array then doubling it in size, so space used is $$O(2n)$$->$$O(n)$$.

*/

void printArray(int* array, int arraySize) {
    for(int i = 0; i < arraySize; i++) {
        printf("%d,", array[i]);
    }
    printf("\n");
}

int main(void) {
 
    int array1[] = {1,2,1};
    int output1Size;
    int* output1 = getConcatenation(array1, 3, &output1Size);
    printf("Expecting [1,2,1,1,2,1] got ");
    printArray(output1, output1Size);
    free(output1);
    
    int array2[] = {1,3,2,1};
    int output2Size;
    int* output2 = getConcatenation(array2, 4, &output2Size);
    printf("Expecting [1,3,2,1,1,3,2,1] got ");
    printArray(output2, output2Size);
    free(output2);

    int array3[] = {9};
    int output3Size;
    int* output3 = getConcatenation(array3, 1, &output3Size);
    printf("Expecting [9,9] got ");
    printArray(output3, output3Size);
    free(output3);
    
    return 0;
}