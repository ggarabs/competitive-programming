#include <bits/stdc++.h>
#define MAXN 107

using namespace std;

int prmd[MAXN][MAXN], dp[MAXN][MAXN], p_sum[MAXN][MAXN];

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> prmd[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(j == 0) p_sum[i][j] = 0;
            else p_sum[i][j] = prmd[i][j] + p_sum[i][j-1];
        }
    }

    for(int i = 1; i <= n; i++) dp[1][i] = p_sum[1][i]-p_sum[1][i-1];

    for(int i = 2; i <= n; i++){
        for(int j = 1; j < n-i+2; j++){
            dp[i][j] = (p_sum[i][j+i-1]-p_sum[i][j-1]) + min(dp[i-1][j], dp[i-1][j+1]);
        }
    }

    cout << dp[n][1] << endl;
    
    return 0;
}