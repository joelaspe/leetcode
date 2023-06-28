class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        for num in nums:
            if num != nums[i]:
                i += 1
                nums[i] = num
        return i + 1

sol = Solution();

array1 = [1,1,2]
output1 = sol.removeDuplicates(array1)
print("array 1 should be [1,2,_] and it is actually ",  array1)
print("output1 should be 2, it is actually ", output1)

array2 = [0,0,1,1,1,2,2,3,3,4]
output2 = sol.removeDuplicates(array2)
print("array 2 should be [0,1,2,3,4,_,_,_,_,_,_] and it is actually ", array2)
print("output 2 should be 5 it is actually ", output2)

array3 = [-10,-9,-9,-5,0,2,2,2,3,5]
output3 = sol.removeDuplicates(array3)
print("array 3 should be [-10,-9,-5,0,2,3,5,_,_,_] and it is actually ",array3)
print("output 3 should be 7 it is actually ", output3)
        
array4 = [1]
output4 = sol.removeDuplicates(array4)
print("array 4 should be [1] and it is actually ", array4)
print("output 4 should be 1 it is actually ", output4)
