// Time complexity: O(2^n)
// Space complexity: O(2^n) : https://www.ideserve.co.in/learn/time-and-space-complexity-of-recursive-algorithms#:~:text=To%20conclude%2C%20space%20complexity%20of,would%20be%20O(nm).
// The maximum depth of recurrsion tree is "n" and each function call recurrsive algorithm takes O(2^n / n) space ---> Space com:  O(n * (2^n)/n) = O(2^n)
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
