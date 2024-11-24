#include <bits/stdc++.h>
#define MAXN 57

using namespace std;

char graph[MAXN][MAXN];
bool vis[MAXN][MAXN];

int n, m, desl_x[4] = {0, 0, 1, -1}, desl_y[4] = {1, -1, 0, 0};

bool in_map(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

void DFS(int x, int y){
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int new_x = x + desl_x[i], new_y = y + desl_y[i];
		if(in_map(new_x, new_y) && graph[new_x][new_y] == 'A' && !vis[new_x][new_y]){
			graph[new_x][new_y] = 'T';
			vis[new_x][new_y] = 1;
			DFS(new_x, new_y);
		}
	}
}

int main(){
	while(cin >> n >> m && n && m){
		int orig_x, orig_y;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> graph[i][j];

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(!vis[i][j] && graph[i][j] == 'T'){
					vis[i][j] = 1;
					DFS(i, j);	
				}
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << graph[i][j];
			}
			cout << endl;
		}

		memset(vis, 0, sizeof(vis));
		memset(graph, 'X', sizeof(vis));

		cout << endl;

	}

	return 0;
}
