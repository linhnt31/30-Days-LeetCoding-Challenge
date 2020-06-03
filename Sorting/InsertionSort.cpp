#include<bits/stdc++.h>

using namespace std;

/*Insertion Sort
We assume that we have a sorted sequence a[0..i-1] anf pick element a[i[ and insert into a[0...i-1]
*/
// Time complexity: O(n^2)
// Space complexity: O(1)
// Pros: sorting in place, be useful when input array is almost sorted.
void insertionSort(int a[], int n){
	int key,  j;
	for(int i = 1; i < n; i++){
		key = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > key){
			a[j+1] = a[j];
			j -= 1;
		}
		a[j + 1] = key;
	}
}

void display(int a[], int n){
	for(int i = 0; i < n ; i++){
		cout << a[i] << "  ";
	}
}
int main(){
	int a[] = {4, 3, 2, 1};
	int n = sizeof(a) / sizeof(a[0]);

	insertionSort(a, n);
	display(a,n);
	return 0;
}
