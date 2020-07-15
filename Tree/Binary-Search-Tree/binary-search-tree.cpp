#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
};

Node *makeNode(int key){
	Node *p = new Node();
	p->data = key;
	p->left = p->right = NULL;
	return p;
}

Node *insert(Node *root, int key){
	if(root == NULL){
		return makeNode(key);
	}
	// Tree is not empty
	if(key < root->data){
		root->left = insert(root->left, key);
	}else if(key > root->data){
		root->right = insert(root->right, key);
	}
	// if key == root->data ---> ignore
	return root;
}

void traversing(Node *root){
	if(root != NULL){
		cout << root->data << "\t";
		traversing(root->left);
		traversing(root->right);
	}
}

int sumOfNodes(Node *root){
	if(root == NULL) return 0;
	return (root->data + sumOfNodes(root->left) + sumOfNodes(root->right));
}

bool findNode(Node *root, int key){
	if(root == NULL){
		return false;
	}
	
	if(root->data == key){
		return true;
	}
	
	bool left = findNode(root->left, key);
	if(left){
		return true;
	}
	
	bool right = findNode(root->right, key);
	return right;
}

int main(){
	Node *root = NULL;
	int a[] = { 40, 5, 35, 45, 16, 20, 48, 13, 16, 49, 47 };
	int n = 11;
	for(int i = 0; i < 11; i++){
		root = insert(root, a[i]);
	}
	
	traversing(root);
	
	int sumNodes = sumOfNodes(root);
	cout << "\nTong cua cac nodes la: " << sumNodes;
	
	bool checkNode = findNode(root, 1);
	if(checkNode){
		cout << "\nGia tri co so luong la 1";
	}else{
		cout << "\nKhong tim thay";
	}
	return 0;
}
