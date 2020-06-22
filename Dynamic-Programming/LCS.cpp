#include<bits/stdc++.h>

using namespace std;

string s1 = "stone";
string s2 = "longest";
int m = s1.size(), n = s2.size();

// Ref: https://www.youtube.com/watch?v=sSno9rV8Rhg&t=713s
	//  https://viblo.asia/p/quy-hoach-dong-mot-thuat-toan-than-thanh-E375zy01lGW
	
// Method 1:  Recurrsion
// Time complexity: O(2^n) len(s1) = len(s2) = n
// Space complexity:  O(n)
int LCS_recurr(int i, int j){
	if(i == s1.size() || j == s2.size()){
		return 0;
	}else if(s1[i] == s2[j]){
		return 1 + LCS_recurr(i + 1, j + 1);
	}
	return max(LCS_recurr(i + 1, j), LCS_recurr(i, j + 1));
}


// Method 2: Dynamic programing
// Time complexity: O(m*n)
// Space complexity: O(m*n)
int LCS_dp(){
	int dp[m+1][n+1];
	for(int i = 0 ; i <= m; i++){
		for(int j = 0 ; j <=n ;j++){
			dp[i][j] = 0;
		}
	}

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << "\nDisplay:  \n";
	for(int i = 0 ; i <= m; i++){
		for(int j = 0; j <= n; j++){
			cout << dp[i][j] << "   ";
		}
		cout << endl;
	}
	return dp[m][n];
}
int main(){
	//int ans = LCS_recurr(0, 0);
	int ans = LCS_dp();
	cout << "Result: " << ans;
	return 0;
}
