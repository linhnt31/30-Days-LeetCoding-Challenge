class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0, ans = INT_MIN;
        for(auto x : nums){
            currentSum += x;
            ans = max(ans, currentSum);
            currentSum = max(currentSum, 0);
        }
        return ans;
    }
};
