#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

pair <int, int> sale[MAXN];
pair <bool, int> dp[MAXN][2*MAXN];
int n, m;

pair <bool, int> solve(int index, int r_cans){
	if(dp[index][r_cans].second != -1) return dp[index][r_cans];

	if(index >= n){
		bool left = r_cans == 0;
		return {left, 0};
	}

	pair <bool, int> not_take = solve(index+1, r_cans), take = {false, 0};

	if(r_cans >= sale[index].first){
		pair <bool, int> aux = solve(index, r_cans-sale[index].first);

		if(aux.first) take = {true, max(take.second, sale[index].second + aux.second)};
	}

	pair <bool, int> ans;

	if(take.first){
		if(not_take.first) ans = take.second > not_take.second ? take : not_take;
		else ans = take;
	}else ans = not_take;

	return dp[index][r_cans] = ans;
}

int main(){
	while(cin >> n >> m){
		for(int i = 0; i <= n; i++) for(int j = 0; j <= m; j++) dp[i][j] = {false, -1};

		for(int i = 0; i < n; i++){
			int q, v;
			cin >> q >> v;
			sale[i] = {q, v};
		}

		cout << solve(0, m).second << endl;
	}

	return 0;
}

