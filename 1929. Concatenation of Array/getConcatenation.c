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