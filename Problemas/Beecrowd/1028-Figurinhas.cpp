#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

int dp[MAXN][MAXN];

int gcd(int a, int b){
	if(b > a) swap(a, b);

	if(dp[a][b] != 0) return dp[a][b];

	if(b == 0) return dp[a][b] = a;

	return dp[a][b] = gcd(b, a%b);
}

int main(){
	int n, f1, f2;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> f1 >> f2;

		cout << gcd(f1, f2) << endl;
	}

	return 0;
}
