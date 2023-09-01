class Solution:
    def isValid(self, s: str) -> bool:
        recordStack = []
        charDictionary = {')': '(', ']': '[', '}': '{'}
        for char in s:
            if char == '(' or char == '[' or char == '{':
                recordStack.append(char)
            else:
                #edge case, if we receive a closing bracket while stack is empty
                if len(recordStack) == 0:
                    return False
                if recordStack.pop() != charDictionary[char]:
                    return False
        if len(recordStack) != 0:
            return False
        return True


sol = Solution()

s1 = "()"
output1 = sol.isValid(s1);
print("Test 1: Expecting true got ", output1)

s2 = "()[]{}"
output2 = sol.isValid(s2)
print("Test 2: Expecting true got ", output2)

s3 = "(]"
output3 = sol.isValid(s3)
print("Test 3: Expecting false got ", output3)

s4 = "(((([[[[{{{{}}}}]]]]))))"
output4 = sol.isValid(s4)
print("Test 4: Expecting true got ", output4)

s5 = "(()()(){}{}{}{}{{{{{}}]][}"
output5 = sol.isValid(s5)
print("Test 5: Expecting false got ", output5)

s6 = "("
output6 = sol.isValid(s6)
print("Test 6 (string input length 1): Expecting false got ", output6)

s7 = "(("
output7 = sol.isValid(s7)
print("Test 7: Expecting false got ", output7)

s8 = ")"
output8 = sol.isValid(s8)
print("Test 8: Expecting false got ", output8)

s9 = "){"
output9 = sol.isValid(s9)
print("Test 9: Expecting false got ", output9)

# Intuition: Given an input string that comprises only the characters '(', ')', '{', '}', '[' and ']' we are asked to determine if the input string is valid based on if the parentheses (bracket, curly or normal) are the appropriate type and in order. We need a way to store the opening bracket and the order each opening bracket appeared in. When we start seeing the closing brackets again, look at the most recent think added and see if it matches the expected. A stack structure would seem to work best for this purpose. 

#Approach:  Declare an array to store the record of opening brackets. Begin iterating through the input string, and check if it is an opening bracket, if it is, add that character into the next part of the recordArray. If instead a closing bracket is encountered, we compare the last added bracket in the recordArray and compare it to the closing bracket (i.e. if we have ']' then '[' should be on record) If at any time that comparison fails, return false. After iteration through the input string, do a final check of the tracker index, it should be at 0. If it is not, return false because we didn't fully close out the opening brackets. Otherwise return true.

#Complexity: 
#-Time: We loop through the input array operations once so the time complexity is $$O(n)$$
#-Space: The record array could be as large as the input array at the most, so space complexity is $$O(n)$$.  */

