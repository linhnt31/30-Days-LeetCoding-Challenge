// Time complexity: O(n^2) and Space complexity: O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int ans = 1;
        int* dp = new int[nums.size()];
        dp[0] = 1;
        for(int i = 1 ; i < nums.size(); i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};