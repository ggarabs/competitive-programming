#include <bits/stdc++.h>
#define MAXN 1007
#define MAXP 100007

using namespace std;

int main(){
    int h[MAXN], s[MAXN], dp[MAXN][MAXP], n, x;

    cin >> n >> x;

    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> s[i];

    for(int i = 0; i <= x; i++) dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            if(h[i] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], s[i]+dp[i-1][j-h[i]]);
            }
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}