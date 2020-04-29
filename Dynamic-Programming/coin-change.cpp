// Time complexity: O(amount*n) - n is length of coins[]
// Space complexity: O(amount)
//Solution: F(i) = min[F(i - c)] + 1  vs 1 <= i <= amount and c in coins[]
//DP bottom up
// problem link: https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxVal = amount + 1;
        int dp[maxVal];
        // The maximum number of coins is (amount + 1) --> declaring a array with the same value : (amount + 1)
        fill_n(dp, maxVal, maxVal); // vector<int> dp(maxVal, maxVal);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(auto c : coins){
                if(i >= c){
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];    
    }
};

            
"""Optimized solution"""
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxVal = amount + 1;
        vector<int> dp(maxVal, maxVal);
        dp[0] = 0;
        
        for(auto c : coins){
            for(int i = c ; i <= amount ; ++i){
                dp[i] = min(dp[i], dp[i - c] + 1); // cant calculate 1-coin
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};