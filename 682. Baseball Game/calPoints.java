import java.util.ArrayList;

class Solution {
    public int calPoints(String[] operations) {
        ArrayList<Integer> scoreArray = new ArrayList<Integer>();
        for(int i = 0; i < operations.length; i++) {
            switch(operations[i]) {
                case "+":
                    scoreArray.add(scoreArray.get(scoreArray.size() - 2) + scoreArray.get(scoreArray.size() - 1));
                    break;
                case "C":
                    scoreArray.remove(scoreArray.size()- 1);
                    break;
                case "D":
                    scoreArray.add(scoreArray.get(scoreArray.size() - 1) * 2);
                    break;
                default:
                    scoreArray.add(Integer.parseInt(operations[i]));
            }
        }
        int sum = 0;
        for(int i = 0; i < scoreArray.size(); i++) {
            sum += scoreArray.get(i);
        }
        return sum;
    }
/* Intuition: The problem wants us to create a record that is empty at the beginning of the game. We will store this in an array of numbers []. We will iterate through the input array and on each element check what the operation is. Since the constraints are that there will be at least 2 elements for a + operation and at least 1 element for both C and D operation, we will not have to worry about edge cases. The operations that occur will always deal with the last element of our score array so pop() and push() like operations will be sufficient. At the end, add up the scores and return them.

Approach: Declare a array `scoreArray`. Loop through the input `operations` and using a switch block look at each element to determine the operation to perform. 
If `+`, we will add `scoreArray[scorearray.length-2] + scoreArray[scoreArray.length-1]` and add it to the end of the `scoreArray`. If `C`, we will remove the last element in `scoreArray[i]`; If `D` we will take the previous score in `scoreArray[scoreArray.length-1]` and double it, adding it to the end of the array `scoreArray`. If it's anything else it is guaranteed to be a string representing an integer from the range -3*10^4 to 3*10^4. Add this number to the end of the scoreArray. When the loop iteration is complete, loop through the scoreArray and add it up, then return the final number. Note: All string numbers will need to be convered to integer first. 

Complexity: 
-Time: We loop through the input array operations once, and the score array once which can have a maximum size of n so time complexity is $$O(2n)$$ -> $$O(n)$$
-Space: The score array could be as large as the input array at the most, so space complexity is $$O(n)$$.  */

    public static void main(String[] args) {
        Solution sol = new Solution();
        
        
        String[] array1 = {"5","2","C","D","+"};
        int output1 = sol.calPoints(array1);
        System.out.println("Expecting 30 got " + output1);

        String[] array2 = {"5","-2","4","C","D","9","+","+"};
        int output2 = sol.calPoints(array2);
        System.out.println("Expecting 27 got " + output2);

        String[] array3 = {"1", "C"};
        int output3 = sol.calPoints(array3);
        System.out.println("Expecting 0 got " + output3);
    }
}

