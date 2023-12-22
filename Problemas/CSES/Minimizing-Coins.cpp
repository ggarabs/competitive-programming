#include <bits/stdc++.h>
#define MAXN 1000007

using namespace std;

int dp[MAXN], coin[MAXN];

int main(){
    int n, x;
    cin >> n >> x;

    for(int i = 0; i < n; i++) cin >> coin[i];

    for(int i = 0; i <= x; i++){
        if(dp[i] == 0 && i != 0) continue;
        for(int j = 0; j < n; j++){
            if(i+coin[j] <= x){
                if(dp[i+coin[j]] == 0) dp[i+coin[j]] = 1+dp[i];
                else dp[i+coin[j]] = min(dp[i+coin[j]], 1+dp[i]);
            }
        }
    }

    if(dp[x] == 0) cout << -1 << endl;
    else cout << dp[x] << endl;

    return 0;
}