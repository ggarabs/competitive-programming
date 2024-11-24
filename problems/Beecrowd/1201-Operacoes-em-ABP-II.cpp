#include <bits/stdc++.h>

using namespace std;

struct node{
	int key;
	struct node *left, *right;
};

bool first = false;

node* insert(node *root, int value){
	if (!root){
		root = (node *) malloc(sizeof(node));
		root->key = value;
		root->right = root->left = NULL;
	} else if (root->key < value) root->right = insert(root->right, value);
	else root->left = insert(root->left, value);
	
	return root;
}

node *findMax(node *root){
	if(!root) return NULL;
	else if (!root->right) return root;
	return findMax(root->right);
}

node *pop(node *root, int x){
	node *aux;
	if (!root) return NULL;
	else if (root->key > x) root->left = pop(root->left, x);
	else if (root->key < x) root->right = pop(root->right, x);
	else if (root->left && root->right){
		aux = findMax(root->left);
		root->key = aux->key;
		root->left = pop(root->left, root->key);
    }else{
		aux = root;
		if (!root->left) root = root->right;
		else if (!root->right) root = root->left;
		free(aux);
	}
	return root;
}

bool search(node *root, int value){
	bool right = false, left = false;

	if (!root) return false;
	if (root->key == value) return true;
	if (root->key < value) right = search(root->right, value);
	else left = search(root->left, value);
    return max(left, right);
}

void infix(node *root){
	if (root){
		infix(root->left);
        if(!first) cout << " ";
        first = false;
        cout << root->key;
		infix(root->right);
	}
}
void prefix(node *root){
	if (root){
        if(!first) cout << " ";
        first = false;
        cout << root->key;
		prefix(root->left);
		prefix(root->right);
	}
}
void posfix(node *root){
	if (root){
		posfix(root->left);
		posfix(root->right);
        if(!first) cout << " ";
        first = false;
        cout << root->key;
	}
}

node *findMin(node *root){
	if (!root) return NULL;
	else if (!root->left) return root;
	return findMin(root->left);
}

int main(){
	int num;
    string input;
	node *root = NULL;

	while (cin >> input){
		if (input == "I") cin >> num, root = insert(root, num);
        else if (input == "R") cin >> num, root = pop(root, num);
		else if (input == "P"){
            cin >> num;

			if (search(root, num)) cout << num << " existe" << endl;
			else cout << num << " nao existe" << endl;
		}
		else
		{
			if (input == "INFIXA") first = true, infix(root), cout << endl;
			else if (input == "PREFIXA") first = true, prefix(root), cout << endl;
			else if (input == "POSFIXA") first = true, posfix(root), cout << endl;
		}
    }
}