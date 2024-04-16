#include <bits/stdc++.h>
#define MAXN 8007

using namespace std;

int dp[MAXN];

int main(){
    int n, v[3]; cin >> n;

    for(int i = 0; i < 3; i++) cin >> v[i];

    dp[0] = 1;

    for(int i = 0; i < n; i++){
        if(dp[i] != 0){
            for(int j = 0; j < 3; j++) dp[i+v[j]] = max(dp[i+v[j]], dp[i]+1);
        }
    }

    cout << dp[n]-1 << endl;

    return 0;
}