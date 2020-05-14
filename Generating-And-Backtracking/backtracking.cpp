#include<bits/stdc++.h>
#define MAX_SIZE 1000
using namespace std;

// Ref: https://medium.com/@thucnc/b%C3%A0i-to%C3%A1n-li%E1%BB%87t-k%C3%AA-ph%C6%B0%C6%A1ng-ph%C3%A1p-sinh-v%C3%A0-thu%E1%BA%ADt-to%C3%A1n-quay-lui-backtracking-10f216fee9e

/*Backtracking
- Using recurrsion
- Each element is found by attemping all possible possibility in turn.

- Pseudocode:
attempt (i):
	for v in < possible values of xi >:
		assign xi = v
		if <xi is the last configuration>
			print <result>
		else:
			{ mark as assigned v to xi ( if necessary ) }
			attempt (i + 1)
			{ uncheck v assigned v for x? (if necessary) }
*/
void display(int a[], int &n){
	for(int i = 0 ; i < n ; i++){
		cout << a[i];
	}
	cout << "\n";
}

// Problem 1: Generating a binary sequence by using backtracking
// Space complexity: O(n) - to store recursive call values into the stack - depth of recursive tree = n
// Time complexity: O(n * 2^n)
void binarySequence(int a[], int &n, int i){
	for(int possVal = 0 ; possVal <= 1; possVal++){
		a[i] = possVal;
		if(i == n - 1){
			display(a, n); // O(n) to display configurations.
		}else{
			binarySequence(a, n, i+1);
		}
	}
}

// Problem 2: Generating all permutations of n elements
// Ref: https://www.topcoder.com/generating-permutations/
// Ref: https://nguyenvanhieu.vn/liet-ke-cac-hoan-vi/

bool check1[MAX_SIZE] = {false};    // To check if the value of x is used
void permu(int a[], int n, int i){
	for(int possVal = 1; possVal <= n ; possVal++){  //possible values
		if(!check1[possVal]){
			a[i] = possVal; 
			check1[possVal] = true;
			if(i == n - 1){
				display(a, n);
			}else{
				permu(a, n, i+1);
			}
			check1[possVal] = false;
		}
	}
}

int k = 0;
vector<bool> check(10, false);
vector<int> tmp;
vector<vector<int> > res;

vector<vector<int> > permute(vector<int>& nums) {
    for(int i = 0 ; i < (int) nums.size() ;i++){
        if(!check[i]){
            tmp[k] = nums[i];
            check[k] = true;
            if(k == nums.size() - 1){
                res.push_back(tmp);
            }else{
                k++;
                permute(nums);
            }
            check[k] = false;
        }
            
    }
    return res;
}
int main(){
	//int n; cout << "Enter the value of n: "; cin >> n;
	//int *a = new int[n];
	
	// Problem 1: a binary sequence
	/*
	backtrack(a, n, 0);
	*/
	
	// Problem 2: permutations
	/*
	permu(a, n, 0);
	*/
	vector<int> nums;
	nums.push_back(1);	
	nums.push_back(2);	
	nums.push_back(3);	
	vector<vector<int> > v;
	v.push_back(nums);
	return 0;
}
