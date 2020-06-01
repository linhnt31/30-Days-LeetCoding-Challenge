// Link problem: https://leetcode.com/problems/house-robber/submissions/


// Method 1: memoization
// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int) (nums.size());
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        int *dp = new int[n]; // maximum amount of money that the rober can rob at i
        /*
        -  We 2 two cases:
        + Robing at i and (i - 2) before that
        + Rob at (i - 1) before that
        */
        dp[0] = nums[0]; dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
           dp[i] = max(dp[i-2] + nums[i], dp[i - 1]);
        }
        return dp[n - 1];
    }
};

// Method 2: Recurrsion
// Time complexity: O(2^n)
// Space complexity: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        return recur(nums, nums.size() - 1);
    }
    
    int recur(vector<int>& nums, int n){
        if(n < 0) return 0;
        return max(recur(nums, n - 2) + nums[n], recur(nums, n - 1));
    }
};


// Method 3: DP iterative with 2 variables
// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int first  = 0;
        int second = nums[0];
        
        for(int i = 1 ; i < n ; i++){
            int currentRob = nums[i] + first;
            first = second;
            second = max(second, currentRob);
        }
        
        return second;
    }
};
