# Time complexity: O(n) ... Space complexity: O(1)
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        reach = 0
        for ind, val in enumerate(nums):
            if ind <= reach:
                reach = max(reach, ind + val)
                if reach >= len(nums) - 1:
                    return True
        return False