#include <bits/stdc++.h>
#define MAXN 1000007

using namespace std;

int dp[MAXN];

int main(){
    int n, x; cin >> n >> x;

    vector <int> coins(n, 0);
    for(int i = 0; i < n; i++) cin >> coins[i];

    for(int i = 0; i < x; i++){
        if(dp[i] == 0 && i != 0) continue;
        for(int j = 0; j < n; j++){
            if(i+coins[j] <= x){
                if(dp[i+coins[j]] == 0) dp[i+coins[j]] = dp[i]+1;
                else dp[i+coins[j]] = min(dp[i+coins[j]], dp[i]+1);
            }
        }
    }

    cout << (dp[x] == 0 ? -1 : dp[x]) << endl;

    return 0;
}