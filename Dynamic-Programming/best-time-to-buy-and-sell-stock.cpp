// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    // Time complexity: O(n)
    // Space complexity: O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        /*
        Key:  we need to find the minimum profit from day 0 --> day i
        - We know that maxProfit[i] = maxVal - minVal = prices[i] - minVal(0-->i)
        */
        int minimumProfit = INT_MAX;
        int maximumProfit = 0;
        for(int i = 0 ; i < n ; i++){
            minimumProfit = min(minimumProfit, prices[i]);
            maximumProfit = max(maximumProfit, prices[i] - minimumProfit);
        }
        return maximumProfit;
    }
};