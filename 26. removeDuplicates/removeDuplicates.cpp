#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    
    Solution sol;

    vector<int> array1 = {1,1,2};
    const int output1 = sol.removeDuplicates(array1);
    cout << "Array 1 should be 1,2,_  it is actually\n";
    for(int n : array1) 
        cout << n << ", ";
    cout << "\noutput1 should be 2, it is actually " << output1 << "\n";

    vector<int> array2 = {0,0,1,1,1,2,2,3,3,4};
    const int output2 = sol.removeDuplicates(array2);
    cout << "Array 1 should be 0,1,2,3,4,_,_,_,_,_,_ it is actually\n";
    for(int n : array2) 
        cout << n << ", ";
    cout << "\noutput2 should be 5 it is actually " << output2 << "\n";

    vector<int> array3 = {-10,-9,-9,-5,0,2,2,2,3,5};
    const int output3 = sol.removeDuplicates(array3);
    cout << "array3 should be -10,-9,-5,0,2,3,5,_,_,_it is actually\n";
    for(int n : array3) 
        cout << n << ", ";
    cout << "\noutput 3 should be 7 it is actually " << output3 << "\n";
    
    vector<int> array4 = {1};
    const int output4 = sol.removeDuplicates(array4);
    cout << "array4 should be 1\n";
    for(int n : array4) 
        cout << n << ", ";
    cout << "\noutput4 should be 1 it is actually " << output4 << "\n";

    return 0;
}

/* Intuition:

The problem requires us to remove duplicate elements from a sorted array, i.e., we need to keep only one copy of each element in the array. Since the array is sorted, all duplicate elements will be adjacent to each other, so we can easily remove them by shifting the subsequent elements of the array to the left.

Approach:

We can use two pointers i and j, where i points to the last unique element found so far, and j points to the current element being examined. If nums[i] and nums[j] are equal, we just increment j. Otherwise, we increment i and copy nums[j] to nums[i]. At the end, we return i+1, which represents the length of the modified array.

Complexity:
    Time Complexity: Since we only traverse the array once, the time complexity is O(n)
    Space complexity: The algorithm uses constant extra space, so O(1)
*/