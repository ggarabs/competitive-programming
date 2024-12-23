#include <bits/stdc++.h>
#define lli long long int

const int MAXN = 501*250+7;
const lli MOD = 1e9+7;

using namespace std;

lli dp[MAXN];

int main(){
	int n; cin >> n;

	dp[0] = 1;
	for(int i = 1; i <= n; i++) for(int j = n*(n+1)/2-i; j >= 0; j--) dp[i+j] = (dp[i+j]%MOD + dp[j]%MOD);

	if(n*(n+1) % 4){
		cout << 0 << endl;
		return 0;
	}

	cout << dp[n*(n+1)/4]/2 << endl;

	return 0;
}
