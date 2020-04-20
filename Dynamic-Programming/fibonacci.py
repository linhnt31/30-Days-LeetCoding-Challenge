#Method 1: Using recurtion : Up to bottom
"""
def fib(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fib(n - 1) + fib(n - 2)

n = int(input("Enter the value of n: "))
ans = fib(n)
print("Result: {}".format(ans))
"""

#Method 2: Using iteration + memoization approach
n = int(input("Enter the value of n: "))
dp = [0] * (n + 1)
dp[0] = 0
dp[1] = 1
def fib():
    global n
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]

    return dp[n]

ans = fib()
print(ans)
