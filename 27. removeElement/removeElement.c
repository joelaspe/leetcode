#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int j = numsSize - 1;
    for(int i = 0; i <= j; i++) {
        if(nums[i] == val) {
            nums[i] = nums[j];
            nums[j] = NULL;
            i--;
            j--;

        }
    }
    return j + 1;
}


/* Intuition:

The intuition behind this solution is to iterate through the array and keep track of two pointers i and j. Each pointer will be put at opposite ends of the array. We will iterate through the array from left to right using i as the iterator. If the value at i matches the target value, then we will put the value at j into that position, then we effective "remove" the target value by removing the value at j. This is an indirect way of viewing the removal. Finally decrement both counters and go back through the loop again. We decrement i in this case because it is possible that the next value at j could match the value again. Stop the incrementing when j < i. Return j + 1 as the number of non-matching values.

Approach:

1. Initialize `j` to be `nums.length-1`.
2. Iterate through each element of the input array using the `i` pointer.
3. For each element `num[i]` check if it is equal to the target value.
- If `nums[i]` is equal to `val`, it is a target element
  -Set `nums[i]` equal to `nums[j]` to store the non-target element at the target element
  -Set `nums[j]` to undefined (this is necessary for edge cases where the input array consists of only the target value, for instance [3,3] with val=3, the array must be modified to be [])
  -Decrement `j` by one
  -Decrement `i` by one
4. Continue this process until j is less than i.
5. Return j + 1, as this will represent the total number of non-target elements


Complexity:
    Time Complexity: Since we only traverse the array once with the pointers moving to the middle toward each other, the time complexity is $$O(n)$$
    Space complexity: The algorithm uses constant extra space, so $$O(1)$$

*/

void printArray(int* array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d,", array[i]);
    }
    printf("\n");
}

int main(void) {

    int array1[] = {3,2,2,3};
    int val1 = 3;
    int output1 = removeElement(array1, 4, val1);
    printf("array1 should be [2,2,_,_] it is actually ");
    printArray(array1, 4);
    printf("output1 should be 2, it is actually %d\n", output1);

    int array2[] = {0,1,2,2,3,0,4,2};
    int val2 = 2;
    int output2 = removeElement(array2, 8, val2);
    printf("array2 should be [0,1,4,0,3,_,_,_] it is actually ");
    printArray(array2, 8);
    printf("output2 should be 5, it is actually %d\n", output2);

    int array3[] = {1};
    int val3 = 2;
    int output3 = removeElement(array3, 1, val3);
    printf("array3 should be [1] it is actually ");
    printArray(array3, 1);
    printf("output3 should be 1 it is actually %d\n", output3);

    int array4[] = {1};
    int val4 = 1;
    int output4 = removeElement(array4, 1, val4);
    printf("array4 should be [] it is actually ");
    printArray(array4, 1);
    printf("output4 should be 0 it is actually %d\n", output4);

    //int* array5 = {};
    int array5[] = {}; // empty array case
    int val5 = 0;
    int output5 = removeElement(array5, 0, val5);
    printf("array5 should be [] it is actually ");
    printArray(array5, 0);
    printf("output5 should be 0 it is actually %d\n", output5);

    int array6[] = {3,3};
    int val6 = 3;
    int output6 = removeElement(array6, 2, val6);
    printf("array6 should be [] it is actually ");
    printArray(array6, 2);
    printf("output6 should be 0 it is actually %d\n", output6);

    int array7[] = {4,5};
    int val7 = 4;
    int output7 = removeElement(array7, 2, val7);
    printf("array7 should be [5] it is actually ");
    printArray(array7, 2);
    printf("output7 should be 1 it is actually %d\n", output7);

    int array8[] = {4,5};
    int val8 = 5;
    int output8 = removeElement(array8, 2, val8);
    printf("array8 should be [4] it is actually ");
    printArray(array8, 2);
    printf("output8 should be 1, it is actually %d\n", output8);
}
