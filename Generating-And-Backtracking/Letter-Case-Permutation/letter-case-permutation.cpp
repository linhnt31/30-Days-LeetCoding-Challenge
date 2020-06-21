// Time complexity: O(2^n)
// Space complexity: O(n)
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(0, res, S);
        return res;
    }
    
    void backtrack(int ind, vector<string> &res, string &s){
        if(ind == s.size()){
            res.push_back(s);
            return;
        }
        
        backtrack(ind+1, res, s);
        if(isalpha(s[ind])){
            s[ind] ^= 32;  //toggling the letter 
            backtrack(ind+1, res, s); // backtracking
        }
    }
};
