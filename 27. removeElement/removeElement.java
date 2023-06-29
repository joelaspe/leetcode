import java.util.Arrays;

class Solution {
    public int removeElement(int[] nums, int val) {
        int j = nums.length - 1;
        for(int i = 0; i <= j; i++) {
            if(nums[i] == val) {
                nums[i] = nums[j];
                nums[j] = -1;
                i--;
                j--;
            }
        }       
        return j + 1;
    }

    public static void main(String args[]) {
        Solution sol = new Solution();

        int[] array1 = {3,2,2,3};
        int val1 = 3;
        int output1 = sol.removeElement(array1, val1);
        System.out.println("array1 should be [2,2,_,_] it is actually " + Arrays.toString(array1));
        System.out.println("output1 should be 2, it is actually " + output1);
        
        int[] array2 = {0,1,2,2,3,0,4,2};
        int val2 = 2;
        int output2 = sol.removeElement(array2, val2);
        System.out.println("array2 should be [0,1,4,0,3,_,_,_] it is actually " + Arrays.toString(array2));
        System.out.println("output2 should be 5, it is actually " + output2);
        
        int[] array3 = {1};
        int val3 = 2;
        int output3 = sol.removeElement(array3, val3);
        System.out.println("array3 should be [1] it is actually " + Arrays.toString(array3));
        System.out.println("output3 should be 1 it is actually " + output3);
        
        int[] array4 = {1};
        int val4 = 1;
        int output4 = sol.removeElement(array4, val4);
        System.out.println("array4 should be [] it is actually " + Arrays.toString(array4));
        System.out.println("output4 should be 0 it is actually " + output4);
        
        int[] array5 = {};
        int val5 = 0;
        int output5 = sol.removeElement(array5, val5);
        System.out.println("array5 should be [] it is actually " + Arrays.toString(array5));
        System.out.println("output5 should be 0 it is actually " + output5);
        
        int[] array6 = {3,3};
        int val6 = 3;
        int output6 = sol.removeElement(array6, val6);
        System.out.println("array6 should be [] it is actually " + Arrays.toString(array6));
        System.out.println("output6 should be 0 it is actually " + output6);
        
        int[] array7 = {4,5};
        int val7 = 4;
        int output7 = sol.removeElement(array7, val7);
        System.out.println("array7 should be [5] it is actually " + Arrays.toString(array7));
        System.out.println("output7 should be 1 it is actually " + output7);
        
        int[] array8 = {4,5};
        int val8 = 5;
        int output8 = sol.removeElement(array8, val8);
        System.out.println("array8 should be [4] it is actually " + Arrays.toString(array8));
        System.out.println("output8 should be 1, it is actually " + output8);
                
    }
}

