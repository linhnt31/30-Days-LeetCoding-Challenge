class Solution:
    # Time complexity: O(n)
    # Space complexity: O(1)
    def maxProfit(self, prices: List[int]) -> int:
        minProfit = float("inf")
        maxProfit = 0
        for p in prices:
            minProfit = min(minProfit, p)
            maxProfit = max(maxProfit, p - minProfit)
        return maxProfit