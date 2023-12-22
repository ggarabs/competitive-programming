#include <bits/stdc++.h>
#define MAXN 1000107

using namespace std;

int dp[MAXN];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < MAXN; i++) dp[i] = MAXN;

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int value = i;
        while(value > 0){
            int digit = value%10;
            if(value != 0) dp[i] = min(dp[i], 1+dp[i-digit]);
            value /= 10;
        }
    }

    cout << dp[n] << endl;

    return 0;
}