"""
There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top.

---> Remember: because the distance is different, so we don't worry about the coincidence of values.
ways(0) = 1
ways(1) = 1
ways(n) = ways(n - 1) + ways(n - 2). (condition: n >= 2)
"""


import timeit

#Method 1: Using recurrsion
# Time complexity: O(2 ^ n)....Space complexity: O(1)
"""
def solve(n):
    if n < 0: 
        return 0
    if n == 0: 
        return 1
    return solve(n - 1) + solve(n - 2)

if __name__ == "__main__":
    n = int(input("The number of stairs: "))
    ans = solve(n)
    print("Result: {}".format(ans))
""" 
# Method 2: Optimize recurrsion method, up-to-bottom
# Time complexity: O(n) .... Space complexity: O(n)
""" 
start = timeit.default_timer()
n = 4
value = [0] * (n + 1) #contains values that are computed
value[0] = 1
check = [False] * (n + 1) # checks if that the values are calcualated or not
check[0] = True

def solve(x):
    if x < 0: 
        return 0
    if check[x] == True:
        return value[x]
    value[x] = solve(x - 1) + solve(x - 2)
    #check[x] = True

    return value[x]

ans = solve(n)
stop = timeit.default_timer()
time = stop - start
print('Time: ', stop - start)  
print(ans, time / 5)
"""

# Method 3: Using dynamic programming
# Time complexity: O(n * k) : n- the number of stairs; k - the length of stair 
""" 
harder problem: The person can climb a set stair = [1, 2, 3,..] at a time.
example: stair = [1, 2, 3] #k
"""
n = int(input("The number of stairs: "))
stair = [1, 2, 3]
dp = [0] * (n + 1)
dp[0] = 1


def solve(x):
    for i in range(1, n + 1):
        dp[i] = 0
        for s in stair:
            if i - s >= 0:
                dp[i] += dp[i - s]
    return dp[n]
    
if __name__ == "__main__":
    ans = solve(n)
    print("Result: {}".format(ans))