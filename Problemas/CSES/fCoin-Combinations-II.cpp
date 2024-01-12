#include <bits/stdc++.h>
#define MAXN 107
#define MAXV 1000007
#define INF 1000000007

using namespace std;

int dp[MAXV][MAXN];

int main(){
    int n, x, coin[MAXN];
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> coin[i];
        dp[coin[i]][coin[i]] = 1;
    }

    sort(coin, coin+n);

    for(int i = 1; i < x; i++){
        for(int j = 0; j < n; j++){
            if(dp[i][coin[j]] == 0 && i != 0) continue;
            for(int k = j; k < n; k++){
                dp[i+coin[k]][coin[k]] += dp[i][coin[j]];
                dp[i+coin[k]][coin[k]] %= INF;
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) ans = (ans + dp[x][coin[i]])%INF;

    cout << ans << endl;

    return 0;
}