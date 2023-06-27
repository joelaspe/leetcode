#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int i = 0;
    for(int j = 1; j < numsSize; j++) {
        if(nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

void printArray(int* array, int arraySize) {
    for(int i = 0; i < arraySize; i++) {
        printf("%d,", array[i]);
    }
    printf("\n");
}

int main()
{
    int array1[] = {1,1,2};
    const int output1 = removeDuplicates(array1, 3);
    printf("Array 1 should be 1,2,_ \n");
    printArray(array1, 3);
    printf("output1 should be 2, it is actually %d\n", output1);

    int array2[] = {0,0,1,1,1,2,2,3,3,4};
    const int output2 = removeDuplicates(array2, 10);
    printf("Array 1 should be 0,1,2,3,4,_,_,_,_,_,_\n");
    printArray(array2, 10);
    printf("output2 should be 5 it is actually %d\n", output2);

    int array3[] = {-10,-9,-9,-5,0,2,2,2,3,5};
    const int output3 = removeDuplicates(array3, 10);
    printf("array3 should be -10,-9,-5,0,2,3,5,_,_,_\n");
    printArray(array3, 10);
    printf("output 3 should be 7 it is actually %d\n", output3);
    
    int array4[] = {1};
    const int output4 = removeDuplicates(array4, 1);
    printf("array4 should be 1\n");
    printArray(array4, 1);
    printf("output4 should be 1 it is actually %d\n", output4);
    
    return 0;
}