# Explain in nextPermutation.cpp
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 1
        while i > 0 and nums[i - 1] >= nums[i]:
            i -= 1
        
        if i == 0:
            nums.reverse()
            return None
        
        j = len(nums) - 1
        while nums[j] <= nums[i - 1]:
            j -= 1
        
        nums[j], nums[i - 1] = nums[i - 1], nums[j]
        
        #Reverse
        self.reverse(nums, i)
        
    def reverse(self, nums, start):
        i = start
        j = len(nums) - 1
        while i < j:
            nums[i], nums[j] = nums[j], nums[i]
            i += 1
            j -= 1

        
