#include <bits/stdc++.h>
#define MAXN 37

using namespace std;

char mapa[MAXN][MAXN];
int desl_x[] = {0, 0, -1, 1}, desl_y[] = {1, -1, 0, 0}, n, m, k;

void DFS(int x, int y){
	mapa[x][y] = '1';
	for(int i = 0; i < 4; i++){
		int new_x = x + desl_x[i], new_y = y + desl_y[i];
		if(new_x <= 0 || new_x > m || new_y <= 0 || new_y > n) continue;
		if(mapa[new_x][new_y] == '.'){
			DFS(new_x, new_y);
		}
	}
}

int main(){
	cin >> n >> m >> k;

	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			mapa[i][j] = '.';
		}
	}

	for(int i = 0; i < k; i++){
		int c, l;
		char dir;
		cin >> c >> l >> dir;

		if(dir == 'N') 	for(int j = l; j >= 1; j--) mapa[j][c] = '*';
		else if(dir == 'S') for(int j = l; j <= m; j++) mapa[j][c] = '*';
		else if(dir == 'L') for(int j = c; j <= n; j++) mapa[l][j] = '*';
		else for(int j = c; j >= 1; j--) mapa[l][j] = '*';
	}

	if(mapa[1][1] == '.') DFS(1, 1);

	if(mapa[m][n] == '1') cout << 'S' << endl;
	else cout << 'N' << endl;

	return 0;
}
