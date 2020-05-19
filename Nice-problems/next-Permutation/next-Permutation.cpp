// Ref: https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
// Link Leetcode:  https://leetcode.com/problems/next-permutation/

// Time complexity: O(n)
// Space complexity: O(1) - in-place
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // FInd longest non-increasing suffix 
        // May be [3,2, 0] or [3, 1, 1] or [1, 1]
        int i = nums.size() - 1;
        while(i > 0 && nums[i- 1] >= nums[i]){
            i--;
        }
        
        // Now i is the head of the suffix
        // If i == 0 --> we at the last configuration
        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Call nums[i - 1] be the pivot
        // Find the rightmost element that is smallest element in the suffix and exceeds the pivot
        // j >= i
        int j = nums.size() - 1;
        while(nums[j] <= nums[i - 1]){
            j--;
        }
        // Now the value nums[j] will become the new pivot
        swap(nums[j], nums[i-1]);
        
        // Because we have the suffix that has non-increasing order--> we only need reverse it instead of sort
        reverse(nums.begin() + i, nums.end());
    }
};
