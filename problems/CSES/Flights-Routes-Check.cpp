#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

vector <int> g[MAXN], ig[MAXN];
bool vis[MAXN];

void DFS(int x, bool mode){
	vis[x] = 1;
	for(int i = 0; i < (int)(mode ? ig[x].size() : g[x].size()); i++){
		int ngbr = (mode ? ig[x][i] : g[x][i]);
		if(!vis[ngbr]) DFS(ngbr, mode);
	}
}

int main(){
	int n, m; cin >> n >> m;

	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		ig[v].push_back(u);
	}

	DFS(1, 0);

	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cout << "NO" << endl;
			cout << "1 " << i << endl;
			return 0;
		}
	}

	for(int i = 1; i <= n; i++) vis[i] = 0;
	DFS(1, 1);

	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			cout << "NO" << endl;
			cout << i << " 1" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}
