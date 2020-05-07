// Method 1: Using division
// Time complexity: O(n)
// Space complexity: O(1) - follow description
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        
        vector<int> res;
        int countZero = 0, product = 1;
        
        for(auto val : nums){
            if(val != 0){
                product *= val;
            }else{
                countZero++;
            }
        }
        
        if(countZero == 0){
            for(auto val : nums){
                res.push_back(product / val);
            }
        }else if(countZero == 1){
            for(auto val : nums){
                if(val == 0){
                    res.push_back(product);
                }else{
                    res.push_back(0);
                }
            }
        }else{
            for(int i = 0 ; i < nums.size(); i++){
                res.push_back(0);
            }
        }
        return res;
    }
};

// Same as Method 1: Optimize a little bit - declaring a vector of 0 elements, we dont check countZero >= 2
// Time complexity: O(n)
// Space complexity: O(1) - follow description
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        if(n <= 1) return nums;
        
        vector<int> res(n);
        int countZero = 0, product = 1;
        
        for(auto val : nums){
            if(val != 0){
                product *= val;
            }else{
                countZero++;
            }
        }
        
        if(countZero == 0){
            for(int i = 0 ; i < n; ++i){
                res[i] = product / nums[i];
            }
        }else if(countZero == 1){
            for(int i = 0 ; i < n; ++i){
                if(nums[i] == 0){
                    res[i] = product;
                }else{
                    res[i] = 0;
                }
            }
        }
        return res;
    }
};