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
		cout << a[i] << "    ";
	}	
}
/* Buble Sort
- We compare 2 consecutive elements and after each round of the algorithm, the largest element will be in the correct position.
- Key word : swap consecutive elements
- Cons: 
+ Time complexity: O(n^2)
*/

void bubleSort(int *a, int n){
	for(int i = 0 ; i < n; i++){
		for(int j = 1; j < n; j++){
			if(*(a + j - 1) > *(a + j) ){
				swap(*(a + j - 1), *(a+j));
			}
		}
	}
}

/* Merge Sort
- is based-on recurrsion and Devide and conquer algorithm
- Steps: 
+ Find the middle: m = (l + r) / 2
+ sort the first half arr[l...m]
+ sort the second half arr[m + 1 ... r]
+ Merge 2 halves
*/
// Time complexity: O(nlogn) - in all cases : worst, average and best
//- Because merge sort always divides the array into two halves and take linear time to merge two halves.
// Space complexity: O(n)
void merge(int a[], int l, int mid, int r){
	int size1 = mid - l + 1;
	int size2 = r - mid;
	
	int L[size1], R[size2]; /// Tmp arrays
	
	//Copy data to 2 tmp arrays
	for(int i = 0; i < size1; i++)
		L[i] = a[l + i];
	for(int i = 0; i < size2; i++)
		R[i] = a[mid + 1 + i];		
	
	int i = 0, j = 0, k = l;
	/* Merge the temp arrays back into a[l..r]*/
	// Time complexity: O(size1 + size2) or in the worst case: O(size1 + size2 = mid-l+1 +r-mid = r-l+1=n) = O(n)
	while(i < size1 && j < size2){
		if(L[i] < R[j]){
			a[k] = L[i];
			i++;
		}else{
			a[k]  = R[j];
			j++;
		}
		k++;
	}
	
	// Copy the remaining elements of L[], if there are any
	while(i < size1){
		a[k] = L[i];
		i++; 
		k++;
	}
	while(i < size2){
		a[k] = R[j];
		j++; 
		k++;
	}
}

void mergeSort(int a[], int l, int r){
	//Time comlexity: O(depth of recurrsion) = O(logn)
	if(r > l){
		int mid = l + (r - l) / 2; // = (r + l) / 2 ---> To avoid overflow for large l and h
		// Sort first and second halves
		mergeSort(a, l, mid); 
		mergeSort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

// Recommend: using sort func
void sortFunc(){
	vector<int> v;
	for(int i = 0 ; i < 10; i++){
		v.push_back(rand()%10+1);
	}
	
	cout << "\nBefore sorting " << endl;
	for(int i = 0 ; i < 10; i++){
		cout << v[i] << "  ";
	}
	
	//sort(v.begin(), v.end());
	sort(v.rbegin(), v.rend()); // a reverse order
	
	cout << "\nAfter sorting sorting " << endl;
	for(int i = 0 ; i < v.size(); i++){
		cout << v[i] << " ";
	}
	
	string s = "hello world";
	sort(s.begin(), s.end());
	cout << endl << s;
}

int main(){
	int a[MAX_SIZE];
	int n; cout << "Enter the number of element: "; cin >> n;
	
	input(a, n); display(a, n);
	cout << "\nAfter sorting: " <<"\n";

	//bubleSort(a, n); 
	
	//mergeSort(a, 0, n - 1);
	
	// using sort function
	sort(a, a+n); // normal array
	display(a, n);
	sortFunc(); // vector
	
	return 0;
}
