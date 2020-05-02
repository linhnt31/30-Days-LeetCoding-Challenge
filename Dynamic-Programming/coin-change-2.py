# Time conmplexity: O(amount * lenOfCoins) ... Space complexity: O(amount)
# Detail explain: in file .cpp
# Link Leetcode: https://leetcode.com/problems/coin-change-2/submissions/
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        dp = [0] * (amount + 1)
        dp[0] = 1
        
        for c in coins:
            for x in range(c, amount + 1):
                dp[x] += dp[x-c] # dp[x] = dp[x - 1] + dp[x-2] + dp[x-5]
        return dp[amount]
                