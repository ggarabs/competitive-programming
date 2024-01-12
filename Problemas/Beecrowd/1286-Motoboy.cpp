#include <bits/stdc++.h>
#define MAXN 27

using namespace std;

pair<int, int> order[MAXN];
int n, p, dp[2*MAXN][MAXN];

int solve(int space, int index){
	if(dp[space][index] != -1) return dp[space][index];
	if(index >= n) return 0;

	int not_take = solve(space, index+1), take = 0;

	if(space >= order[index].second) take = order[index].first + solve(space - order[index].second, index+1);

	return dp[space][index] = max(take, not_take);
}

int main(){
	while(cin >> n){
		if(n == 0) break;
		cin >> p;

		memset(dp, -1, sizeof(dp));

		for(int i = 0; i < n; i++){
			int time, qtd;
			cin >> time >> qtd;
			order[i] = {time, qtd};
		}

		cout << solve(p, 0) << " min." << endl;
	}

	return 0;
}
