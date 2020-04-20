# Time complexity: O(nm) ... Space complexity: O(mn)
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[0 for i in range(n)] for j in range(m)]
        
        for i in range(m):
            for j in range(n):
                if (i - 1) < 0:
                    dp[i - 1][j] = 0
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j]
                elif (j - 1) < 0:
                    dp[i][j-1] = 0
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j]
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        return dp[m-1][n-1]
                    