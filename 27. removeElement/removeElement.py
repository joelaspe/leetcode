from typing import List
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        j = len(nums) - 1
        while i <= j:
            if nums[i] == val:
                nums[i] = nums[j]
                nums[j] = None
                i -= 1
                j -= 1
            i += 1
        return j + 1

sol = Solution()

array1 = [3,2,2,3]
val1 = 3
output1 = sol.removeElement(array1, val1)
print("array1 should be [2,2,_,_] it is actually ", array1)
print("output1 should be 2, it is actually ", output1)

array2 = [0,1,2,2,3,0,4,2]
val2 = 2
output2 = sol.removeElement(array2, val2)
print("array2 should be [0,1,4,0,3,_,_,_] it is actually ", array2)
print("output2 should be 5, it is actually ",output2)

array3 = [1]
val3 = 2
output3 = sol.removeElement(array3, val3)
print("array3 should be [1] it is actually ", array3)
print("output3 should be 1 it is actually ", output3)

array4 = [1]
val4 = 1
output4 = sol.removeElement(array4, val4)
print("array4 should be [] it is actually ", array4)
print("output4 should be 0 it is actually ", output4)

array5 = []
val5 = 0
output5 = sol.removeElement(array5, val5)
print("array5 should be [] it is actually ", array5)
print("output5 should be 0 it is actually ", output5)

array6 = [3,3]
val6 = 3
output6 = sol.removeElement(array6, val6)
print("array6 should be [] it is actually ", array6)
print("output6 should be 0 it is actually ", output6)

array7 = [4,5]
val7 = 4
output7 = sol.removeElement(array7, val7)
print("array7 should be [5] it is actually ", array7)
print("output7 should be 1 it is actually ", output7)

array8 = [4,5]
val8 = 5
output8 = sol.removeElement(array8, val8)
print("array8 should be [4] it is actually ", array8)
print("output8 should be 1, it is actually ", output8)

