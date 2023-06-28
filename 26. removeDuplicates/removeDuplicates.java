import java.util.Arrays;

class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0;
        for(int j = 1; j < nums.length; j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }

    public static void main(String args[]) {
        Solution sol = new Solution();

        int[] array1 = {1,1,2};
        int output1 = sol.removeDuplicates(array1);
        System.out.println("array 1 should be [1,2,_] and it is actually " + Arrays.toString(array1)); 
        System.out.println("output1 should be 2, it is actually " + output1);
        
        int[] array2 = {0,0,1,1,1,2,2,3,3,4};
        int output2 = sol.removeDuplicates(array2);
        System.out.println("array 2 should be [0,1,2,3,4,_,_,_,_,_,_] and it is actually " + Arrays.toString(array2));
        System.out.println("output 2 should be 5 it is actually " + output2);
        
        int[] array3 = {-10,-9,-9,-5,0,2,2,2,3,5};
        int output3 = sol.removeDuplicates(array3);
        System.out.println("array 3 should be [-10,-9,-5,0,2,3,5,_,_,_] and it is actually " + Arrays.toString(array3));
        System.out.println("output 3 should be 7 it is actually " +  output3);
                
        int[] array4 = {1};
        int output4 = sol.removeDuplicates(array4);
        System.out.println("array 4 should be [1] and it is actually " + Arrays.toString(array4));
        System.out.println("output 4 should be 1 it is actually " + output4);
    }
}
/* Intuition:

The problem requires us to remove duplicate elements from a sorted array, i.e., we need to keep only one copy of each element in the array. Since the array is sorted, all duplicate elements will be adjacent to each other, so we can easily remove them by shifting the subsequent elements of the array to the left.

Approach:

We can use two pointers i and j, where i points to the last unique element found so far, and j points to the current element being examined. If nums[i] and nums[j] are equal, we just increment j. Otherwise, we increment i and copy nums[j] to nums[i]. At the end, we return i+1, which represents the length of the modified array.

Complexity:
    Time Complexity: Since we only traverse the array once, the time complexity is O(n)
    Space complexity: The algorithm uses constant extra space, so O(1)
*/