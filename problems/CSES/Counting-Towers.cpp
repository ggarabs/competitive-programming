#include <bits/stdc++.h>
#define mod %
#define lli long long int

using namespace std;

const int MAXN = 1e6+7, INF = 1e9+7;

lli dp[MAXN][2];

int main(){
    int t, maxh = 2; cin >> t;
    while(t--){
        int n; cin >> n;

        dp[1][0] = 1, dp[1][1] = 1, dp[2][0] = 5, dp[2][1] = 3;

        if(n > maxh){
            for(int i = maxh; i <= n; i++){
                dp[i][0] = (4*dp[i-1][0] mod INF + dp[i-1][1]) mod INF;
                dp[i][1] = (dp[i-1][0] + 2*dp[i-1][1] mod INF) mod INF;
            }    
        }

        maxh = max(maxh, n);

        cout << (dp[n][0] + dp[n][1]) mod INF << endl;
    }
    return 0;
}