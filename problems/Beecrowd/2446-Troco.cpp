#include <bits/stdc++.h>
#define MAXN 100007
#define MAXM 1007

using namespace std;

bool dp[MAXN][MAXM];

int main(){
	int v, m; cin >> v >> m;

	vector <int> moedas(m+1, 0);
	for(int i = 1; i <= m; i++) cin >> moedas[i];

	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= v; j++){
			if(moedas[j] > j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], 1+dp[i-1][j-moedas[i]]);
		}
	}

	if(dp[v]) cout << "S" << endl;
	else cout << "N" << endl;

	return 0;
}
