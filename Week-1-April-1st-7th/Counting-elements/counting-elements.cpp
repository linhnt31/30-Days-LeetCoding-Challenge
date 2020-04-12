// Time complexity: O(n) .... Space complexity: O(n)
class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> s;
        int ans = 0;
        for(auto a : arr){
            s.insert(a); //O(1)
        }
        for(auto a: arr){
            ans += 1 ? s.count(a + 1) == 1 : 0;
        }
        return ans;
    }
};