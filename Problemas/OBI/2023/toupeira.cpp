#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

int grafo[MAXN][MAXN];

int main(){
	int s, t;
	cin >> s >> t;

	for(int i = 0; i < t; i++){
		int x, y;
		cin >> x >> y;
		grafo[x][y] = 1;
		grafo[y][x] = 1;
	}

	int p, ans = 0;
	cin >> p;

	for(int i = 0; i < p; i++){
		int n, ant, atual;
		bool possivel = true;
		cin >> n >> ant;

		for(int j = 1; j < n; j++){
			cin >> atual;
			if(grafo[ant][atual] == 0) possivel = false;
			ant = atual;
		}

		if(possivel) ans++;
	}

	cout << ans << endl;

	return 0;
}
