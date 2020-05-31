#include <bits/stdc++.h>
using namespace std;

// Link problem: https://leetcode.com/problems/edit-distance/submissions/
// Ref: 	https://www.geeksforgeeks.org/edit-distance-dp-5/

/* Edit distance 
- Editing operations needed (insert, remove, modify) to transform a string into another string.
*/

/* Idea
1. If last character of 2 strings are the same --> Nothing to do --> Recur (m-1, n-1)
2. Else, compute minimum cost for 3 operations:
+ Insert, Recur (m, n-1)
+ Remove, Recur (m - 1, n)
+ Modify, Recur (m-1, n-1)
*/

// Min fuction to find minimum of three numbers
int minThreeValues(int x, int y, int z){
	return min(min(x, y), z);
}

// Method 1: Recurrsive
// Time complexity: O(3^m) or O(3^n)
// Space complexity: O(m) or O(n)
int editDistance(string str1, string str2, int m, int n){
	if(m == 0){
		return n;
	}
	
	if(n == 0){
		return m;
	}
	
	if(str1[m-1] == str2[n - 1]){
		return editDistance(str1, str2, m - 1, n - 1);
	}
	
	return 1 + minThreeValues(editDistance(str1, str2, m, n - 1),
							  editDistance(str1, str2, m - 1, n),								
							  editDistance(str1, str2, m - 1, n - 1)
							);
}


// Method 2: DP
// Time complexity: O(m*n)
// Space complexity: O(m*n)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // dp[i][j] is the minimum number of operations to convert word1[0:i) to word2[0:j)
        vector<vector<int> > dp(m + 1, vector<int>(n+1, 0));
        
        for(int i = 1 ; i <= m; ++i){
            dp[i][0] = i;
        }
        
        for(int j = 1; j <= n; ++j){
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};
int main(){
	// Method 1: Recurrsive
	string str1 = "Sunday";
	string str2 = "Saturday";
	
	cout << editDistance(str1, str2, str1.length(), str2.length());
	return 0;
}
