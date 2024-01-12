#include <bits/stdc++.h>
#define MAXV 100007
#define MAXM 1007

using namespace std;

int moedas[MAXM], m;
bool dp[MAXV];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, 0, sizeof(dp));
	dp[0] = true;

	int v;
	cin >> v >> m;

	for(int i = 0; i < m; i++) cin >> moedas[i];

	for(int i = 0; i < m; i++){
		for(int j = v - moedas[i]; j >= 0; j--){
			if(dp[j] == true) dp[j+moedas[i]] = true;
			}
	}

	cout << (dp[v] ? 'S':'N') << endl;

	return 0;
}
