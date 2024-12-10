#include <bits/stdc++.h>
#define MAXN 200007
 
using namespace std;
 
vector <int> tree[MAXN];
bool vis[MAXN];
int p_leaf, max_l;
 
void DFS(int x, int l){
	for(int i = 0; i < tree[x].size(); i++){
		int curr = tree[x][i];
		if(!vis[curr]){
			vis[curr] = 1;
			if(max_l < l+1){
				max_l = l+1;
				p_leaf = curr;
			}
			DFS(curr, l+1);
		}
	}
}
 
int main(){
	int n; cin >> n;
 
	for(int i = 0; i < n-1; i++){
		int u, v; cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
 
	vis[1] = 1;
	DFS(1, 0);

	for(int i = 1; i <= n; i++) vis[i] = 0;
	max_l = 0;
 
	vis[p_leaf] = 1;
	DFS(p_leaf, 0);
 
	cout << max_l << endl;
 
	return 0;
}
