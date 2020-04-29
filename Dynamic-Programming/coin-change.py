# Time complexity: O(amount*n) - n is length of coins[]
# Space complexity: O(amount)
# Solution: F(i) = min[F(i - c)] + 1  vs 1 <= i <= amount and c in coins[]
# DP bottom up
# Problem link: https://leetcode.com/problems/coin-change/ 
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        maxVal = amount + 1
        dp = [maxVal] * maxVal
        dp[0] = 0
        
        for i in range(1, maxVal):
            for c in coins: 
                if i >= c:
                    dp[i] = min(dp[i], dp[i - c] + 1)
        if dp[amount] > amount:
            return -1 
        return dp[amount]
