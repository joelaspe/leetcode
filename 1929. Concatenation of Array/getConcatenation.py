from typing import List
class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ans = []
        i = 0
        while i < 2 * len(nums):
            ans.append(nums[i % len(nums)])
            i += 1
        return ans


## An internet solution that should work
#class Solution:
#    def getConcatenation(self, nums: List[int]) -> List[int]:
#        return nums*2

## Another internet solution that should work
#class Solution:
#    def getConcatenation(self, nums: List[int]) -> List[int]:
#        return nums+nums


sol = Solution()

array1 = [1,2,1]
output1 = sol.getConcatenation(array1)
print("Expecting [1,2,1,1,2,1] got ", output1)

array2 = [1,3,2,1];
output2 = sol.getConcatenation(array2)
print("Expecting [1,3,2,1,1,3,2,1] got ", output2)

array3 = [9]
output3 = sol.getConcatenation(array3)
print("Expecting [9,9] got ", output3)