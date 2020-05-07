# Method 2
# Time complexity : O(n)
# Space complexity: O(1) --> Read description
# Another solution: Read file.cpp
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)
        
        # First, we construct ans as a prefix product : ans[L...i]
        ans[0] = 1 # Because no element to the left
        for i in range(1, len(nums)):
            ans[i] = ans[i - 1] * nums[i - 1]
        
        # Next, we will combine computation between suffix product [i....R] and ans[i] contains the product 
        R = 1 # Because no element to the right
        for i in range(len(nums) - 1, -1, - 1):
            ans[i] = R * ans[i]
            R *= nums[i]
        return ans