#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adjMatrix[], int u, int v){
	adjMatrix[u].push_back(v);
	adjMatrix[v].push_back(u); // For undirected graph
}

void display(vector<int> adjMatrix[], int V){
	for(int i = 0 ; i < V; i++){
		cout << "\n Adjacency list of vertex " << i << "\nHead";
		for(int j = 0 ; j < adjMatrix[i].size(); j++){
			cout << " -> " << adjMatrix[i][j]; 
		}
	}
}
int main(){
	int V = 5; 
    vector<int> adj[V]; 
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    display(adj, V); 	
	return 0;
}
