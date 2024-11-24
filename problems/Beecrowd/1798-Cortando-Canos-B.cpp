#include <bits/stdc++.h>
#define MAXN 2007

using namespace std;

int c[MAXN], v[MAXN], dp[MAXN];

int main(){
	int n, t; cin >> n >> t;

	for(int i = 0; i < n; i++) cin >> c[i] >> v[i];

	for(int j = 1; j <= t; j++){
		for(int i = 0; i < n; i++){
			if(c[i] > j) continue;
			dp[j] = max(dp[j], dp[j-c[i]]+v[i]);
		}
	}

	cout << dp[t] << endl;

	return 0;
}
