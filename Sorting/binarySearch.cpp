#include<bits/stdc++.h>
#define MAX_SIZE 1000
using namespace std;


void input(int *a, int n){
	for(int i = 0 ; i < n; i++){
		a[i] = (rand() % 10);
	}	
}

void display(int *a, int n){
	cout << "\nMy array: ";
	for(int i = 0 ; i < n ; i++ ){
		cout << *(a + i) << "    ";
	}	
	cout << endl;
}

/* Binary Search
- For **the array sorted**
- Time complexity: O(logn)

*/
vector<int> result; 
// if the value fined is unique
bool binarySearch(int *a, int left, int right, int target){
	bool checkExist = NULL;
	while(left <= right){
		int mid = (left + right) / 2;
		if(*(a + mid) == target){
			result.push_back(mid);
			checkExist = true;
		}
		else if(*(a + mid) > target){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	if(checkExist == false){
		return false;
	}
	return true;
}

// If the value fined is not unique
// For example: a = [1, 2, 2, 2, 4, 5] and the target value equals = 2
// Time complexity: O(logn + k) - k is the number of occurences of the target number
// Refer: https://stackoverflow.com/questions/13197552/using-binary-search-with-sorted-array-with-duplicates
void specialBinarySearch(int a[], int n, int left, int right, int target){
	// Find the first index of the target number
	int firstInd = -1;
	while(left <= right){ // array may have a one element so we need the case : left == right
		int mid = left + (right - left) / 2; // to avoid overflow for large numbers
		if(a[mid] == target){
			firstInd = mid;
			right = mid - 1;
		}
		else if(a[mid] > target){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	
	cout << "First Index : " << firstInd << endl;
	// Find the last index of the target number
	left = firstInd;
	right = n - 1;
	int endInd = -1;
	while(left <= right){
		int mid  = left + (right - left) / 2;
		if(a[mid] == target){
			endInd = mid;
			left = mid + 1;
		}
		else if(a[mid] > target){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	
	cout << "End Index: " << endInd << endl;
	// Print the all index where a[indexs] = target
	cout << "Result: " << endl;
	if(firstInd != -1 && endInd != -1){
		for(int i = firstInd; i <= endInd; i++){
			cout << i << "    ";
		}
	}else{
		cout << "\nThe value is not exist";
	}
}
int main(){
	int a[MAX_SIZE];
	int n; cout << "Enter the number of element: "; cin >> n;
	input(a, n); display(a, n);
	
	sort(a, a + n);
	cout << "\n After sorting: ";
	display(a, n);
	
	int target; cout << "\nEnter the target: "; cin >> target;\
	// If the target number is unique
	/*
	bool checkInd = binarySearch(a, 0, n - 1, target);
	if(checkInd == false){
		cout << "\nThe value is not exist";
		return 0;
	}

	for(int i = 0 ; i < result.size(); i++){
		cout << "\nThe value sits on " << result[i] << " position"; 
	} */
	
	// If the target number is not unique
	specialBinarySearch(a, n, 0, n-1, target);
	return 0;
}
