#include <bits/stdc++.h>
#define MAXN 507
#define INF 250007

using namespace std;

int main(){
    int a, b; cin >> a >> b;

    if(a > b) swap(a, b);

    int dp[MAXN][MAXN];

    for(int i = 1; i <= a; i++){
        for(int j = i; j <= b; j++){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = dp[j][i] = INF;
        }
    }

    for(int i = 1; i <= a; i++){
        for(int j = i; j <= b; j++){
            for(int k = 1; k <= j/2; k++) dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
            for(int k = 1; k <= i/2; k++) dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
            dp[j][i] = dp[i][j];
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}