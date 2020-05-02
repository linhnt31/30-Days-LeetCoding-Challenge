// Time conmplexity: O(amount * lenOfCoins) ... Space complexity: O(amount)
// dp(x) denotes the ***number of ways*** we can form the sum x
// If x < 0 --> return 0 ---> because there is no solution
// If x == 0 --> return 1 ---> Because we have only the one way to form 
// example: coins = [2,3,4] --> dp(x) = dp(x-2) + dp(x-3) + dp(x-4)

//Link Leetcode: https://leetcode.com/problems/coin-change-2/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount < 0) return 0;
        //vector<int> dp(amount+1, 0);
        int dp[amount + 1];fill_n(dp, amount+1, 0);
        dp[0] = 1;
        for(auto c : coins){
            for(int i = c ; i <= amount ; i++){
                dp[i] += dp[i - c];
            }
        }
        return dp[amount];
    }
};