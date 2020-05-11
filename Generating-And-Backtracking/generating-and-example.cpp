#include<bits/stdc++.h>
using namespace std;

// Ref: https://medium.com/@thucnc/b%C3%A0i-to%C3%A1n-li%E1%BB%87t-k%C3%AA-ph%C6%B0%C6%A1ng-ph%C3%A1p-sinh-v%C3%A0-thu%E1%BA%ADt-to%C3%A1n-quay-lui-backtracking-10f216fee9e

/*Generation algorithm

- The listed problems can be solved by generating all **configurations** in turn.
- To do that, we need to meet the 2 conditions: 
+ We must know the first and last configurations
+ Building nan algorithm from a configuration that is not the last configuration and it can generate the next configuration it

- Pseudocode:
<Build the first configuration> 
while true:
	<Printing the current configuration> 
	if current == last configuration:
		break
	<Generating the next configuration> 
*/



// Problem 1: Generate a binary sequence of length n 
/* We need remember a rule to solve this problem
ex: 000		 001        011
  + 001		 001	    001
  = 001      	 010	    100

- Idea: I simply plus the current number with 1 (the last bit equals 1)  (= 001 with n = 3 or = 0001 with n = 4)
*/
void generate(int a[], int &n){
	++a[n - 1];
	for(int i = n - 1; i > 0; i--){
		if(a[i] > 1){
			++a[i-1];
			a[i] -= 2;
		}
	}
}

void display(int a[], int &n){
	for(int i = 0 ; i < n ; i++){
		cout << a[i];
	}
	cout << "\n";
}

int main(){
	// Problem 1: Generate a binary sequence of length n
	/*
	int n; cout << "Enter the length of binary sequence: " ; cin >> n;
	int *currentSequence = new int[n]{0};
	for(int i = 0 ; i < (int)(pow(2, n)); i++){
		display(currentSequence, n);
		generate(currentSequence, n);
	} */
	
	return 0;
}
