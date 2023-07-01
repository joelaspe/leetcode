#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < (nums.size() * 2); i++) 
            ans.push_back(nums[i % nums.size()]);
        return ans;
    }
};

/* 
Intuition: I'm seeing a lot of solutions that just add onto the input array using push and then returning the input array. The problem wants us to concatenate the input array with itself, effectively returning a new array that is twice as long as the original. The input array should not be modified. We can start by iterating through the array and add onto the end of the array. We will do this twice so the loop size will be twice the size of the input array. We will use the modulo operator to only have to use one loop.

Approach: Create a new empty array `ans`. Begin by iterating through the array `nums`. On each iterator `i` add the current element onto the end of `ans`. We use the modulo operator `%` which will come into effect once i is greater than input length. Once the iteration is complete, return `ans`.

Time Complexity: We are copying the array twice so total is $$O(2n)$$ -> $$O(n)$$.

Space complexity: We are creating a whole new copy of the array then doubling it in size, so space used is $$O(2n)$$->$$O(n)$$.

*/

void printArray(vector<int>& array) {
    cout << "[";
    for(int n : array) {
        cout << n << ",";
    }
    cout << "]";
}

int main() {
    
    Solution sol;

    vector<int> array1 = {1,2,1};
    vector<int> output1 = sol.getConcatenation(array1);
    cout << "Expecting [1,2,1,1,2,1] got ";
    printArray(output1);
    cout << "\n";
            
    vector<int> array2 = {1,3,2,1};
    vector<int> output2 = sol.getConcatenation(array2);
    cout << "Expecting [1,3,2,1,1,3,2,1] got ";
    printArray(output2);
    cout << "\n";
    
    vector<int> array3 = {9};
    vector<int> output3 = sol.getConcatenation(array3);
    cout << "Expecting [9,9] got ";
    printArray(output3);
    cout << "\n";
        
    return 0;
}