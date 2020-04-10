// Method 1: Time complexity=O(n^2), Space complexity: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& a) {
        for(int i = 0 ; i < a.size() - 1; i++){
            // var i only follows zero elements
            if(a[i] != 0) continue;
            // var j only follows non-zero elements
            for(int j = i + 1; j < a.size(); j++){
                if(a[j] == 0) continue;
                else{
                    int tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                    break; // after swap 2 elements, we must break the loop to avoid subsequent elements with a[i]
                } 
            }
        }
    }
};

// Method 2: Time complexity; O(n), Space comlexity: O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> tmp;
        for(auto v : nums){
            if(v != 0){
                tmp.push_back(v);
            }
        }
        for(int i = 0 ; i < nums.size(); i++){
            if(i < tmp.size()){
                nums[i] = tmp.at(i);
            }
            else{
                nums[i] = 0;
            }
        }
    }
};

// Method 3: Time complexity=O(n), Space complexity: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // the number of non-zero elements
        int non = 0;
        for(auto v : nums){
            if(v != 0){
                nums[non++] = v;
            }
        }
        for(int i = non; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};