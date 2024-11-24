#include <bits/stdc++.h>
#define MAXN 57

using namespace std;

vector <int> tree[MAXN];
bool vis[MAXN];

int convert(string num){
	int aux = 0, pot = 1;
	for(int i = num.size()-1; i >= 0; i--, pot *= 10){
		aux += (num[i]-'0')*pot;
	}
	return aux;
}

void DFS(int x){
	cout << "(" << x;
	for(int i = 0; i < tree[x].size(); i++){
		cout << " ";
		DFS(tree[x][i]);
	}
	cout << ")";
}

int main(){
	string list;
	while(getline(cin, list)){
		if(list == ""){
			cout << "(1)" << endl;
			continue;
		}
		string n = "";
		int curr;
		vector <int> values;
		for(char aux : list){
			if(aux == ' '){ 
				curr = convert(n);
				values.push_back(curr);
				n = "";
			}else n += aux;
		}
		curr = convert(n);
		values.push_back(curr);

		set<int>dentro;
		vector<int>entrou(values.size(), 0);

		for(int i = values.size()-1; i >= 0; i--){
			if(!dentro.count(values[i])){
				dentro.insert(values[i]);
				entrou[i] = 1;
			}
		}

		priority_queue <int, vector<int>, greater<int>> folhas;

		for(int i = 1; i <= values.size()+1; i++){
			if(!dentro.count(i)) folhas.push(i);
		}

		for(int i = 0; i < values.size(); i++){
			tree[values[i]].push_back(folhas.top());
			folhas.pop();
			if(entrou[i]) folhas.push(values[i]);	
		}

		int root = folhas.top();

		DFS(root);
		cout << endl;

		for(int i = 0; i < MAXN; i++) tree[i].clear();

	}
}
