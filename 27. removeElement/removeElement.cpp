#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size() - 1;
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
};

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

int main() {

    Solution sol;
    
    vector<int> array1 = {3,2,2,3};
    int val1 = 3;
    int output1 = sol.removeElement(array1, val1);
    cout << "array1 should be [2,2,_,_] it is actually ";
    for(int n : array1) {
        cout << n << ",";
    }
    cout << "\noutput1 should be 2, it is actually " << output1 << "\n";

    vector<int> array2 = {0,1,2,2,3,0,4,2};
    int val2 = 2;
    int output2 = sol.removeElement(array2, val2);
    cout << "array2 should be [0,1,4,0,3,_,_,_] it is actually ";
    for(int n : array2) {
        cout << n << ",";
    }
    cout << "\noutput2 should be 5, it is actually " << output2 << "\n";

    vector<int> array3 = {1};
    int val3 = 2;
    int output3 = sol.removeElement(array3, val3);
    cout << "array3 should be [1] it is actually ";
    for(int n : array3) {
        cout << n << ",";
    }
    cout << "\noutput3 should be 1 it is actually " << output3 << "\n";

    vector<int> array4 = {1};
    int val4 = 1;
    int output4 = sol.removeElement(array4, val4);
    cout << "array4 should be [] it is actually ";
    for(int n : array4) {
        cout << n << ",";
    }
    cout << "\noutput4 should be 0 it is actually " << output4 << "\n";

    vector<int> array5 = {};
    int val5 = 0;
    int output5 = sol.removeElement(array5, val5);
    cout << "array5 should be [] it is actually ";
    for(int n : array5) {
        cout << n << ",";
    }
    cout << "\noutput5 should be 0 it is actually " << output5 << "\n";

    vector<int> array6 = {3,3};
    int val6 = 3;
    int output6 = sol.removeElement(array6, val6);
    cout << "array6 should be [] it is actually ";
    for(int n : array6) {
        cout << n << ",";
    }
    cout << "\noutput6 should be 0 it is actually " << output6 << "\n";

    vector<int> array7 = {4,5};
    int val7 = 4;
    int output7 = sol.removeElement(array7, val7);
    cout << "array7 should be [5] it is actually ";
    for(int n : array7) {
        cout << n << ",";
    }
    cout << "\noutput7 should be 1 it is actually " << output7 << "\n";

    vector<int> array8 = {4,5};
    int val8 = 5;
    int output8 = sol.removeElement(array8, val8);
    cout << "array8 should be [4] it is actually ";
    for(int n : array8) {
        cout << n << ",";
    }
    cout << "\noutput8 should be 1, it is actually " << output8 << "\n";

}