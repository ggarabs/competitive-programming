#include <bits/stdc++.h>
#define lli long long int

using namespace std;

const lli INF = 1e5*1e5;

int main(){
    int n, k; cin >> n >> k;

    vector <int> bonecas(n, 0);
    vector <vector <lli>> dp(n+1, vector <lli>(k+1));

    for(int i = 0; i < n; i++){
        dp[i][0] = 0;
        for(int j = 1; j < k+1; j++) dp[i][j] = INF;
    }

    for(int i = 0; i < n; i++) cin >> bonecas[i];

    sort(bonecas.begin(), bonecas.end());

    for(int i = n-1; i >= 0; i--){
        for(int j = 1; j <= min((n-i)/3, k); j++){
            dp[i][j] = min(dp[i+1][j], (bonecas[i+1]-bonecas[i])*(bonecas[i+1]-bonecas[i]) + dp[i+2][j-1]);
        }
    }

    cout << dp[0][k] << endl;

    return 0;
}