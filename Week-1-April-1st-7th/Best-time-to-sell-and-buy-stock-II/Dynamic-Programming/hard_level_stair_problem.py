"""
There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top at most k jumps
"""

n = int(input("Enter the number of stairs: "))
k = int(input("Enter the maximum jump to reach top: "))

dp = [[0 for i in range(k+1)] for j in range(n+1)]
dp[0][1]= dp[1][1] = 1
dp[1][0] = dp[0][0] = 0

def solve():
    for i in range(1, n + 1):
        for j in range(1, k + 1):
            for c in [1, 2]:
                if i >= c:
                    dp[i][j] += dp[i-c][j]
    ans = 0
    for i in range(k+1):
        ans += dp[n][i]
    
    print("Result {}".format(ans))

solve()

