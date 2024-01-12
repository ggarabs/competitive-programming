#include <bits/stdc++.h>
#define MAXN 107
#define MAXX 1000007
#define MAXV 1000000007

using namespace std;

int dp[MAXX];

int main(){
    int n, x, coin[MAXN];
    cin >> n >> x;

    for(int i = 0; i < n; i++) cin >> coin[i];

    dp[0] = 1;

    for(int i = 0; i < x; i++){
        if(dp[i] == 0 && i != 0) continue;
        for(int j = 0; j < n; j++){
            if(i+coin[j] <= x) dp[i+coin[j]] = (dp[i] + dp[i+coin[j]])%MAXV;
        }
    }

    cout << dp[x] << endl;

    return 0;
}