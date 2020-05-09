#include<bits/stdc++.h>
using namespace std;

void showPq(priority_queue <int> q){
	priority_queue<int> g = q;
	while(!g.empty()){
		cout << "\t" << g.top(); // O(1)
		g.pop(); // O(logn)
	}
	cout << endl;
}

void test(){
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	
	priority_queue<int> v(a.begin(), a.end());
	
	while(!v.empty()){
		cout << v.top() << "   ";
		v.pop();
	}
	cout << endl;
}
int main(){
	test();
	priority_queue<int> v; // O(n)

	v.push(10);
	v.push(20);
	v.push(30); // O(logn)
	v.push(40);
	
	cout << "The priority queue v is: ";
	showPq(v);
	return 0;
}
