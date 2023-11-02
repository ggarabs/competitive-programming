#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int moedas[MAXN], dp[MAXN], m;

int coin_change(int value, int ind){
	if(dp[value] != -1) return dp[value];
	if(ind >= m) return dp[value] = 0;
	
	int take = 0;

	for(int i = 0; i*moedas[ind] <= value; i++){
		take = max(take, coin_change(value-i*moedas[ind], ind+1));
	}

	return dp[value] = take;
}

int main(){
	int v;
	cin >> v >> m;

	memset(dp, -1, sizeof(dp));
	dp[0] = 1;

	for(int i = 0; i < m; i++) cin >> moedas[i];

	cout << (coin_change(v, 0) == 1 ? 'S':'N') << endl;

	return 0;
}
