class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(nums, 0, res);
        return res;
    }
    
    void backtrack(vector<int>& nums, int ind, vector<vector<int> >& res){
        if(ind == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        
	// Fill positions one by one and we need to know that are all our choices

        for(int i = ind ; i < nums.size(); i++){ // choices
            swap(nums[ind], nums[i]); // take a choice and mark it as done for position ind
            backtrack(nums, ind + 1, res);
            swap(nums[ind], nums[i]); //backtrack
        }
    }
};
