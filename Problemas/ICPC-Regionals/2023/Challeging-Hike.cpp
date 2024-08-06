#include <bits/stdc++.h>
#define MAXN 10010
#define pb push_back

using namespace std;

vector <int> tree[MAXN];
int likes[MAXN], resp[MAXN];
bool vis[MAXN];

void DFS(int node, vector <int> pilha){
	vector <int>::iterator it = lower_bound(pilha.begin(), pilha.end(), likes[node]);
	int p = it - pilha.begin();

	if(it == pilha.end()) pilha.pb(likes[node]);
	else *it = likes[node];

	resp[node] = pilha.size();
	
	for(int i = 0; i < tree[node].size(); i++){
		int child = tree[node][i];
		if(vis[child]) continue;
		vis[child] = true;
		DFS(child, pilha);
	}
}

int main(){
	int n; cin >> n;

	for(int i = 2; i <= n; i++){
		int node; cin >> node;
		tree[node].pb(i);
		tree[i].pb(node);
	}

	for(int i = 1; i <= n; i++) cin >> likes[i];

	vis[1] = true;
	vector <int> st;
	DFS(1, st);

	for(int i = 2; i <= n; i++) cout << resp[i] << " ";
	cout << endl;

	return 0;
}
