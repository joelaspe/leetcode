import java.util.Arrays;

class Solution {
    public int[] getConcatenation(int[] nums) {
        int[] ans = new int[nums.length * 2];
        for(int i = 0; i < (nums.length * 2); i++) 
            ans[i] = nums[i % nums.length];
        return ans;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] array1 = {1,2,1};
        int[] output1 = sol.getConcatenation(array1);
        System.out.println("Expecting [1,2,1,1,2,1] got " + Arrays.toString(output1));
        
        int[] array2 = {1,3,2,1};
        int[] output2 = sol.getConcatenation(array2);
        System.out.println("Expecting [1,3,2,1,1,3,2,1] got " + Arrays.toString(output2));
        
        int[] array3 = {9};
        int[] output3 = sol.getConcatenation(array3);
        System.out.println("Expecting [9,9] got " + Arrays.toString(output3));
    }

}

/* 
Intuition: I'm seeing a lot of solutions that just add onto the input array using push and then returning the input array. The problem wants us to concatenate the input array with itself, effectively returning a new array that is twice as long as the original. The input array should not be modified. We can start by iterating through the array and add onto the end of the array. We will do this twice so the loop size will be twice the size of the input array. We will use the modulo operator to only have to use one loop.

Approach: Create a new empty array `ans`. Begin by iterating through the array `nums`. On each iterator `i` add the current element onto the end of `ans`. We use the modulo operator `%` which will come into effect once i is greater than input length. Once the iteration is complete, return `ans`.

Time Complexity: We are copying the array twice so total is $$O(2n)$$ -> $$O(n)$$.

Space complexity: We are creating a whole new copy of the array then doubling it in size, so space used is $$O(2n)$$->$$O(n)$$.

*/