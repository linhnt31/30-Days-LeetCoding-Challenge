// Link problem: https://leetcode.com/problems/is-subsequence/

// Method 1:
// Time complexity: O(t.size())
// Space complexity: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0, check = 0;
        while(i < s.size() && j < t.size()){
            if(s[i] == t[j]){
                check++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return check == s.size();
    }
};