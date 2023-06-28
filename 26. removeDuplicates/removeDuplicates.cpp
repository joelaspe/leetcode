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