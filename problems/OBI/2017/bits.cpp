#include <bits/stdc++.h>
#define MAXN 1007
#define MAXV 1000000007

using namespace std;

int dp[MAXN][MAXN];

int main(){
    int n, k;
    cin >> n >> k;

    dp[0][0] = 1;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= min(k-1, i); j++){
            if(j != k-1) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MAXV;
            dp[i+1][0] = (dp[i+1][0] + dp[i][j]) % MAXV;
        }
    }

    int ans = 0;

    for(int i = 0; i < k; i++) ans = (ans + dp[n][i]) % MAXV;

    cout << ans << endl;

    return 0;
}