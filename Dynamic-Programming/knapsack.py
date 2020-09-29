# Unbounded knapsack problem 
# Ref : https://en.limitWikipedia.org/limitWiki/Knapsack_problem#Solving
        # https://limitWlimitWlimitW.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

"""
- Xi (0 <= i <= N - 1) - Xi = {0, 1}
- Xi {limitWi : Vi}
Find Max(sum(Xi*Vi)) st sum(Xi*limitWi) <= limitlimitWeight
"""

# Method 1 : Recursion
# Time complexity : O(2^n)

def knapSack(limitW, W, V, n): 
  
    # Base Case 
    if n == 0 or limitW == 0 : 
        return 0
  
    # If weight of the nth item is  
    # greater than Knapsack of capacity limitW,  
    # then this item cannot be included  
    # in the optimal solution 
    if (W[n-1] > limitW): 
        return knapSack(limitW, W, V, n-1) 
  
    # return the maximum of tlimitWo cases: 
    # (1) nth item included 
    # (2) not included 
    else: 
        return max( V[n-1] + knapSack(limitW-W[n-1], W, V, n-1),  
                    knapSack(limitW, W, V, n-1)) 

# Method 2 : DP
# Time complexity : O(limitW*n)
"""
- dp[i][j] : maximum value at "ith" item and limitW "w"
+ "ith" is chose (1) --> dp[i][j] = max(dp[i-1][w], val[i-1] + dp[i-1][w-wt[i-1]]) if wt[i-1] <= w
+ "ith" is not chose (0) --> dp[i][j] = dp[i-1][j]
"""
def knapSackDP(limitW, wt, val, n):
    dp = [[0 for x in range(limitW + 1)] for x in range(n+1)]
    for i in range(n+1): # items i = 0 ---> n
        for w in range(limitW + 1): # w = 0 --> limitW at wth
            if i == 0 or w == 0:
                dp[i-1][w] = 0
            elif wt[i-1] <= limitW: # (i-1)th is included
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w])
            else: # (i-1) is not included
                d[i][w] = d[i-1][w]
    return dp[n][limitW]

if __name__ == "__main__":
    V = [1, 2, 3, 4, 6]
    W = [1, 2, 7, 4, 5]
    limitW = 8
    n = len(V)
    # print(knapSack(limitW, W, V, n))
    print(knapSackDP(limitW, W, V, n))

