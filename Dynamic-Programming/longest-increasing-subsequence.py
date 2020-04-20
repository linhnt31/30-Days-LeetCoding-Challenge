"""Description
Given an unsorted array of integers ( called A), find the length of longest increasing subsequence.

Example:
Input: A = [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
"""
# Solution
"""
We suppose that: 
+ n - is the length of array
+ Li = max(Li, Lj + 1) : is the length of longest increasing subsequence at i index
with 0 < j < i < n and A[i] > a[j]

*** Calculate Li: We will calculate the length of longest increasing subsequence at j index where Aj < Ai. 
                  Then, we plus the value Ai ( account for (Lj + 1) ). As a result, we will have maximum value needed.
"""

# Time complexity: O(n^2) and Space complexity: O(n)

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        max_length = [0] * len(nums)
        max_length[0] = 1
        ans = 1
        for i in range(1, len(nums)):
            max_length[i] = 1
            for j in range(0, i):
                if nums[i] > nums[j]:
                    max_length[i] = max(max_length[i], max_length[j] + 1)
            ans = max(ans, max_length[i])
        return ans

# Problem: https://leetcode.com/problems/longest-increasing-subsequence/