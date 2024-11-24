#include <bits/stdc++.h>
#define MAXN 107

using namespace std;

int duration[MAXN], point[MAXN], t, n;
int dp[6*MAXN][MAXN];

int solve(int time, int ind){
	if(dp[time][ind] != -1) return dp[time][ind];
	if(ind >= n) return dp[time][ind] = 0;

	int take = 0;

	for(int i = 0; i*duration[ind] <= time; i++) take = max(take, i*point[ind]+solve(time-i*duration[ind], ind+1));
	
	return dp[time][ind] = take;
}

int main(){
	int cont = 1;
	while(cin >> n >> t){
		if(n == 0 && t == 0) break;

		memset(dp, -1, sizeof(dp));

		for(int i = 0; i < n; i++) cin >> duration[i] >> point[i];

		cout << "Instancia " << cont << endl;
		cout << solve(t, 0) << endl << endl;
		cont++;
	}

	return 0;
}
