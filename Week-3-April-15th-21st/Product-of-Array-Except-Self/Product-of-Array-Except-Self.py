# Method 2
# Time complexity : O(n)
# Space complexity: O(1) --> Read description
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

# Method 1
# Time complexity: O(n)
# Space complexity: O(1) --> Read follow up of the description
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product_without_zeros = 1
        count_zeros = 0
        res = [0] * len(nums)
        
        for val in nums:
            if val != 0:
                product_without_zeros *= val
            else:
                count_zeros += 1
        
        if count_zeros == 0:
            for key, val in enumerate(nums):
                res[key] = product_without_zeros // val
        elif count_zeros == 1:
            for key, val in enumerate(nums):
                if val == 0:
                    res[key] = product_without_zeros
        return res
