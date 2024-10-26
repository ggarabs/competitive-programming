#include <bits/stdc++.h>
#define MAXN 57
#define MAXP 107

using namespace std;

int w[MAXN], power[MAXN], dp[MAXN][MAXP];

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i = 1; i <= n; i++) cin >> power[i] >> w[i];
		int k, r; cin >> k >> r;

		memset(dp, 0, sizeof(dp));

		for(int i = 1; i <= n; i++){
			for(int j = 0; j <= k; j++){
				if(w[i] > j) dp[i][j] = dp[i-1][j];
				else dp[i][j] = max(dp[i-1][j], power[i]+dp[i-1][j-w[i]]);
			}
		}

		if(dp[n][k] >= r) cout << "Missao completada com sucesso" << endl;
		else cout << "Falha na missao" << endl;
	}
	return 0;
}
