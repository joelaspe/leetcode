import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        Stack recordArray = new Stack();
        
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '(' || s.charAt(i) == '{' || s.charAt(i) == '[') {
                recordArray.push(s.charAt(i));
            } else {
                //edge case, if stack is empty due to receiving a closing bracket before an opening one exists on the stack
                if(recordArray.empty()) {
                    return false;
                }
                switch(s.charAt(i)) {
                    case ')': {
                        if((char)recordArray.pop() != '(') {
                            return false;
                        }
                        break;
                    }
                    case '}': {
                        if((char)recordArray.pop() != '{') {
                            return false;
                        }
                        break;
                    }
                    case ']': {
                        if((char)recordArray.pop() != '[') {
                            return false;
                        }
                        break;
                    }
                    default: {
                        return false;
                    }
                }
            }
            
        }
        return recordArray.empty();
    }
    public static void main(String args[]) {

        Solution sol = new Solution();
        
        String s1 = "()";
        boolean output1 = sol.isValid(s1);
        System.out.println("Test 1: Expecting true (1) got " + output1);
        
        
        String s2 = "()[]{}";
        boolean output2 = sol.isValid(s2);
        System.out.println("Test 2: Expecting true (1) got " + output2);
        
        String s3 = "(]";
        boolean output3 = sol.isValid(s3);
        System.out.println("Test 3: Expecting false (0) got " + output3);
        
        String s4 = "(((([[[[{{{{}}}}]]]]))))";
        boolean output4 = sol.isValid(s4);
        System.out.println("Test 4: Expecting true (1) got " + output4);
        
        String s5 = "(()()(){}{}{}{}{{{{{}}]][}";
        boolean output5 = sol.isValid(s5);
        System.out.println("Test 5: Expecting false (0) got " + output5);
        
        String s6 = "(";
        boolean output6 = sol.isValid(s6);
        System.out.println("Test 6 (string input length 1): Expecting false (0) got " + output6);
        
        String s7 = "((";
        boolean output7 = sol.isValid(s7);
        System.out.println("Test 7: Expecting false (0) got " + output7);
        
        String s8 = ")";
        boolean output8 = sol.isValid(s8);
        System.out.println("Test 8: Expecting false (0) got " + output8);
        
        String s9 = "){";
        boolean output9 = sol.isValid(s9);
        System.out.println("Test 9: Expecting false (0) got " + output9);
    }
    
}

/* Intuition: Given an input string that comprises only the characters '(', ')', '{', '}', '[' and ']' we are asked to determine if the input string is valid based on if the parentheses (bracket, curly or normal) are the appropriate type and in order. We need a way to store the opening bracket and the order each opening bracket appeared in. When we start seeing the closing brackets again, look at the most recent think added and see if it matches the expected. A stack structure would seem to work best for this purpose. 

Approach:  Declare an array to store the record of opening brackets. Begin iterating through the input string, and check if it is an opening bracket, if it is, add that character into the next part of the recordArray. If instead a closing bracket is encountered, we compare the last added bracket in the recordArray and compare it to the closing bracket (i.e. if we have ']' then '[' should be on record) If at any time that comparison fails, return false. After iteration through the input string, do a final check of the tracker index, it should be at 0. If it is not, return false because we didn't fully close out the opening brackets. Otherwise return true.

Complexity: 
-Time: We loop through the input array operations once so the time complexity is $$O(n)$$
-Space: The record array could be as large as the input array at the most, so space complexity is $$O(n)$$.  */

