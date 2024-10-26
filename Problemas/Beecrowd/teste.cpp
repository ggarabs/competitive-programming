#include <bits/stdc++.h>

using namespace std;

int dp[1 << 4 - 1][5];

int dist[4][4] = {{0, 10, 15, 20},
			  {10, 0, 35, 25},
			  {15, 35, 0, 30},
			  {20, 25, 30, 0}};


int n = 4;

int tsp(int mask, int i)
{
	if(mask == (1 << n) - 1) return dp[mask][i] = dist[i][0]; // caso todas as cidades já tenham sido visitadas

	if(dp[mask][i] != -1) return dp[mask][i]; // se a DP ja foi calculada

	int ans = 1e9;

	for(int v = 0; v < n; v++)
	{
		if(mask & (1 << v) or !dist[i][v]) continue; // se a cidade atual já foi visitada ou não há rota de i à v

		ans = min(ans, tsp((mask | (1 << v)), v) + dist[i][v]); //pego o minimo entre ir para cada vizinho

	}

	return dp[mask][i] = ans;
}

int tsp_it(int n){
	int mask = (1 << n)-1;

	for(int i = 1; i < n; i++) dp[mask][i] = dist[i][0];

	for (int mask = 1; mask < (1 << n); mask+=2) {
		for (int i = 1; i < n; i++) {
			if (!(mask & (1 << i))) continue;

			for (int j = 1; j < n; j++) {
				if (mask & (1 << j) || !dist[i][j]) continue;

				dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dist[i][j]);
			}
		}
	}

	return dp[mask][0];



}

int main(){
	for(int i = 1; i <= 15; i++){
		for(int j = 0; j < 4; j++){
			dp[i][j] = -1;
		}
	}

	cout << tsp(1, 0) << endl;

	for(int i = 1; i <= 15; i++){
		for(int j = 0; j < 4; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	cout << tsp_it(4) << endl;

	for(int i = 1; i <= 15; i++){
		for(int j = 0; j < 4; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
