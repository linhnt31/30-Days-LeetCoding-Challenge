//Time complexity: O(n)... Space complexity: O(n)
class Solution {
public:
    // prefixSum[L...R] = prefixSum[R] - prefixSum[L-1]
    
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int pref = 0;
        //Hash table
        unordered_map<int, int> countPref; // records the number of subarrays with sum as its key.
        /* To solve the empty prefix
        If  nums[i] = k ---> need = 0 ---> We have a satisfactory case
        */
        countPref[pref]++; 
        
        for(int i = 0 ; i < nums.size(); ++i){
            /* prefixSum[R] = prefixSum[L-1] + k
            ----> need = prefixSum[L-1] = prefixSum[R] ( = pref) - k
            */
            pref += nums[i]; //The current sum at i
            int need = pref - k;
            ans += countPref[need]; // O(1)
            countPref[pref]++;
        }
        return ans;
    }
};