// Time complexity: O(k*nlogn) : k: the numbers of elements of strs and n is maximum length in a string of strs
// Space complexity: O(n)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto s : strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end()); //O(nlogn)
            m[tmp].push_back(s);
        }
        vector<vector<string>> res;
        for(auto pp : m){
            res.push_back(pp.second);
        }
        return res;
    }
};


// Time complexity: O(n*k)
//to_string converts a integer to string
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(auto s : strs){
            int a[26]  = {0};
            string key = "";
            for(auto c : s){
                a[c - 'a'] += 1;
            }
            for(int i = 0 ; i < 26; i++){
                key += '#' + to_string(a[i]);
            }
            m[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto pp : m){
            ans.push_back(pp.second);
        }
        return ans;
    }
};