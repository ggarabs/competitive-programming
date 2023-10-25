#include <bits/stdc++.h>
#define MAXN 107

using namespace std;

int n, m, desl_x[4] = {0, 0, -1, 1}, desl_y[4] = {1, -1, 0, 0};
int tab[MAXN][MAXN];

bool in(int x, int y){ return x >= 0 && x < n && y >= 0 && y < m; }

int solve(int x, int y){
	if(tab[x][y] == 1) return 9;
	int cont = 0;
	for(int i = 0; i < 4; i++){
		int new_x = x + desl_x[i], new_y = y + desl_y[i];
		if(in(new_x, new_y) && tab[new_x][new_y] != 0) cont++;
	}
	return cont;
}

int main(){
	int resp[MAXN][MAXN];
	while(cin >> n >> m){
		memset(resp, 0, sizeof(resp));
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> tab[i][j];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				resp[i][j] = solve(i, j);
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) cout << resp[i][j];
			cout << endl;
		}
	}
	return 0;
}
