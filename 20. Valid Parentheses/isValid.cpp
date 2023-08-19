#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        //edge case, odd length of input string is automatically invalid
        if(s.length() % 2 == 1) {
            return false;
        }
        
        stack<char> recordStack;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                recordStack.push(s[i]);
            } else {
                switch (s[i]) {
                    case ')': {
                        if(recordStack.pop() != '(') {
                            return false;
                        }
                        break;
                    }
                    case ']': {
                        if(recordStack.pop() != '[') {
                            return false;
                        }
                        break;
                    }
                    case '}': {
                        if(recordStack.pop() != '{') {
                            return false;
                        }
                    }
                }
            }
        }
        if(recordStack.size() > 0) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    string s1 = "()";
    bool output1 = sol.isValid(s1);
    cout << "Test 1: Expecting true (1) got " << output1 << "\n";


    string s2 = "()[]{}";
    bool output2 = sol.isValid(s2);
    cout << "Test 2: Expecting true (1) got " << output2 << "\n";

    string s3 = "(]";
    bool output3 = sol.isValid(s3);
    cout << "Test 3: Expecting false (0) got " << output3 << "\n";

    string s4 = "(((([[[[{{{{}}}}]]]]))))";
    bool output4 = sol.isValid(s4);
    cout << "Test 4: Expecting true (1) got " << output4 << "\n";

    string s5 = "(()()(){}{}{}{}{{{{{}}]][}";
    bool output5 = sol.isValid(s5);
    cout << "Test 5: Expecting false (0) got " << output5 << "\n";

    string s6 = "(";
    bool output6 = sol.isValid(s6);
    cout << "Test 6 (string input length 1): Expecting false (0) got " << output6 << "\n";

    string s7 = "((";
    bool output7 = sol.isValid(s7);
    cout << "Test 7: Expecting false (0) got " << output7 << "\n";

    string s8 = ")";
    bool output8 = sol.isValid(s8);
    cout << "Test 8: Expecting false (0) got " << output8 << "\n";

    string s9 = "){";
    bool output9 = sol.isValid(s9);
    cout << "Test 9: Expecting false (0) got " << output9 << "\n";

}

/* Intuition: Given an input string that comprises only the characters '(', ')', '{', '}', '[' and ']' we are asked to determine if the input string is valid based on if the parentheses (bracket, curly or normal) are the appropriate type and in order. We need a way to store the opening bracket and the order each opening bracket appeared in. When we start seeing the closing brackets again, look at the most recent think added and see if it matches the expected. A stack structure would seem to work best for this purpose. 

Approach:  Declare an array to store the record of opening brackets. Begin iterating through the input string, and check if it is an opening bracket, if it is, add that character into the next part of the recordArray. If instead a closing bracket is encountered, we compare the last added bracket in the recordArray and compare it to the closing bracket (i.e. if we have ']' then '[' should be on record) If at any time that comparison fails, return false. After iteration through the input string, do a final check of the tracker index, it should be at 0. If it is not, return false because we didn't fully close out the opening brackets. Otherwise return true.

Complexity: 
-Time: We loop through the input array operations once so the time complexity is $$O(n)$$
-Space: The record array could be as large as the input array at the most, so space complexity is $$O(n)$$.  */