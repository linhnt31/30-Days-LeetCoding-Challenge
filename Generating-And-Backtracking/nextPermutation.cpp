#include<bits/stdc++.h>
using namespace std;

//Ref:  https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
     // https://leetcode.com/articles/next-permutation/
// Method 1: Brute force
// Time complexity: O(n!)
// Space complexity: O(n)
/* Solution
- Step 1: Check all the possible configuration
- Step 2: If the current configuration == vector input --> check = true : preparing to print next permutation
		  Else, backtrack

- This solution is right for input =  [1,2,3,....n] and i haven't check the last configuration (solved by check if the array has decreasing order)
ex: input = [1, 5, 1] or n = 3 and input = [3,2,1] --> output wrong --> This is not good solution

*/
bool check = false; // To check current vector == vector input --> print next vector
int countRes = 0;
void displayRes(vector<int> &v){
	for(int i = 0 ; i < v.size(); i++){
		cout << v[i] << "  ";
	}
}

bool checkEqualVector(vector<int> &tmp, vector<int> &v){
	for(int i = 0 ; i < tmp.size(); ++i){
		if(v[i] != tmp[i]){
			return false;
		}
	}
	return true;
}

void backtracking(vector<int> &v, vector<int> &tmp, int Xi){
	if(check == true && Xi == v.size() - 1 ){
		displayRes(v);
		check = false;
		//return;
	}
	if(Xi == v.size() - 1){
		if(checkEqualVector(tmp, v)){
			check = true;
		}
		for(int i = 0 ; i < v.size(); i++){
			cout << v[i] << "  ";
		}
		cout << endl;
	}
	
	// Check all the possible values of a element Xi in the configuration
	for(int i = Xi ; i < v.size() ;++i){
		swap(v[Xi], v[i]); 
		backtracking(v, tmp, Xi + 1);
		swap(v[Xi], v[i]); // backtracking
	}
}


// Method 2: Without temporary array
/*
*** Idea: we must increase the sequence as little as possible
- Firstly, we need to identify the longest suffix that is non-increasing : O(n) time (we have at least one element because a single element is non-increasing)
- Secondly, look at the element to the left of the suffix and call it pivot 
+ If there if no element, this configuration is already the last permutation
+ The pivot < the head of the suffix
+ If we swap the pivot with the smallest element(= minVal ) in the suffix and minVal > pivot --> the prefix is minized.
- Finnaly, we know that the suffix is non-increasing so we sinply reverse them to make a new suffix.
*/

void nextPermutation(vector<int>& nums){
	//Find longest non-increasing suffix
	int i = nums.size() - 1;
	while(i > 0 && nums[i - 1] >= nums[i]){
		i--;
	}
	// Now i is the head index of the suffix
	// If i == 0 ---> we at the last permutation
	if(i <= 0){
		reverse(nums.begin(), nums.end());
		return;
	}
	
	// Let nums[i - 1] be the pivot
	// Find the rightmost element that is smallest element in the suffix and exceeds the pivot (j >= i)
	int j = nums.size() - 1;
	while(nums[j] <= nums[i - 1]){
		j--;
	}
	
	// Now the value nums[j] will become the new pivot 
	swap(nums[j], nums[i-1]);
	
	// Reverse the suffix 
	reverse(nums.begin() + i, nums.end());
}
int main(){
	// Method 1: 
	/*
	vector<int> v, tmp; 
	int n, input; cin >> n; // The number of element
	for(int i = 0 ; i < n; i++){
		cin >> input;
		tmp.push_back(input);
	}
	for(int i = 1; i <= n ;i++){
		v.push_back(i);
	}
	
	int Xi = 0; // a element in a configuration
	cout << check << "\n";
	backtracking(v, tmp, Xi);  */
	
	// Method 2:
	int t; cin >> t;
	while(t--){
		vector<int> nums; 
		int n, input; cin >> n; // The number of element
		for(int i = 0 ; i < n; i++){
			cin >> input;
			nums.push_back(input);
		}
		
		nextPermutation(nums);
		displayRes(nums);
	}
	return 0;
}
