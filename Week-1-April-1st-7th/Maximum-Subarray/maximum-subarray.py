class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        current_sum = 0
        ans = float("-inf")
        for x in nums:
            current_sum += x
            ans = max(ans, current_sum)
            current_sum = max(current_sum, 0)
        return ans
