#include <bits/stdc++.h>
using namespace std;

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

int main(){
	// Method 1: Recurrsive
	string str1 = "Sunday";
	string str2 = "Saturday";
	
	cout << editDistance(str1, str2, str1.length(), str2.length());
	return 0;
}
