#include <bits/stdc++.h>
#define mod %
#define MAXN 1000007
#define INF 1000000007

using namespace std;

int dp[MAXN];

int main(){
    int n, x; cin >> n >> x;

    vector <int> coin(n, 0);
    for(int i = 0; i < n; i++) cin >> coin[i];

    sort(coin.begin(), coin.end());

    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= x-coin[i]; j++){
            if(dp[j]) dp[j+coin[i]] = (dp[j+coin[i]] + dp[j]) mod INF;
        }
    }

    cout << dp[x] << endl;

    return 0;
}