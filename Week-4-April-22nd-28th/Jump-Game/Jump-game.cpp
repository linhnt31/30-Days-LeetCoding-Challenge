// Time complexity: O(n) .... Space complexity: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        int ind = 0;
        // maxJump is the longest jump distance at a ith index
        for(int maxJump = 0; ind < nums.size() - 1 && ind <= maxJump; ++ind){
            maxJump = max(maxJump, ind + nums[ind]);
            if(maxJump >= nums.size() - 1){
                return true;
            }
        }
        return false;
    }
};