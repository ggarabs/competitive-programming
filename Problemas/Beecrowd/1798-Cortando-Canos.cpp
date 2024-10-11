#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

int n, t, cano[MAXN], valor[MAXN];
long long int dp[2*MAXN][MAXN];


long long int knapsack(int comp, int ind){
	if(ind >= n || comp <= 0) return dp[comp][ind] = 0;
	if(dp[comp][ind] != -1) return dp[comp][ind];

	long long int take = 0;

	for(int i = 0; i*cano[ind] <= comp; i++){
		take = max(take, i*valor[ind]+knapsack(comp-i*cano[ind], ind+1));
	}

	return dp[comp][ind] = take;
}

int main(){
	cin >> n >> t;

	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < n; i++) cin >> cano[i] >> valor[i];

	cout << knapsack(t, 0) << endl;

	return 0;
}
