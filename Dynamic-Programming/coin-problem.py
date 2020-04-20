"""Description
Given a set
of coin values coins = {c1, c2,..., ck} and a target sum of money n, our task is to
form the sum n using as few coins as p
"""

"""We have a fomulation recusively to calculate the minimum number of coins to form sum x

             INF if x < 0
           '
solve(x) = - 0   if x = 0
           ' 
             min(solve(x - c) + 1) if x > 0, c in list of coins [c1, c2,..ck]
"""

#Recursive formulation
#Time complexity: O(k^n) ... k: the number of elements in coins
'''
answer = float('inf') #minimum number of coins
def solve(x, coins):
    global answer
    if x < 0:
        return float('inf')
    elif x == 0:
        return 0
    for c in coins:
        answer = min(answer, solve(x - c, coins) + 1)

    return answer  '''

# Method 2: Using recurrence + memoization = dp..., up-bottom approach
# TIme complexity: O(n) .... Space complexity: O(n)
""" 
target_sum = int(input("Enter the target sum: "))
dp = [0] * (target_sum + 1) #contains the values that are computed
check = [None] * (target_sum + 1)
coins = [1, 3, 4]

def solve(x): # x = target sum
    if x < 0:
        return float('inf')
    if x == 0:
        return 0
    if check[x]:
        return dp[x]
    ans = float('inf')

    for c in coins:
        ans = min(ans, solve(x - c) + 1)
    
    dp[x] = ans 
    check[x] = True 
    return ans 

if __name__ == "__main__":
    ans = solve(target_sum)
    print("Result: {}".format(ans)) """

# Method 3: Using iteration
# Time complexity: O(kn).... Space complexity: O(n)
""" 
target_sum = int(input("Enter the target sum: "))
dp = [0] * (target_sum + 1) #contains the values that are computed
coins = [1, 3, 4]

def solve():  ## x = target_sum
    global target_sum
    for i in range(1, target_sum + 1):
        dp[i] = float('inf')
        for c in coins: 
            if i - c >= 0:
                dp[i] = min(dp[i], dp[i - c] + 1)
    return dp[target_sum]

if __name__ == "__main__":
    ans = solve()
    print("Result: {}".format(ans)) """

# Another questions: Interviewer can request that the values of sum need to be printed.
target_sum = int(input("Enter the target sum: "))
coins = [1, 3, 4]
value = [0] * (target_sum + 1) # contains the values that are computed
first = [0] * (target_sum + 1) # contains the first coin that are used in sub problems
value[0] = 0

def solve(x): 
    for i in range(1, x + 1):
        value[i] = float('inf')
        for c in coins:
            if i - c >= 0 and value[i] > value[i-c] + 1:
                value[i] = value[i - c] + 1 
                first[i] = c 
    
    while(x > 0):
        print("{} ".format(first[x]))
        x -= first[x]
    
    return value[target_sum]

if __name__ == "__main__":
    ans = solve(target_sum)
    print("Result: {}".format(ans))



