#include <bits/stdc++.h>
#define MAXN 100007
#define MOD %
#define INF 1000000007

using namespace std;

long long dp[107][MAXN];

int main(){
    int n, m, array[MAXN];
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> array[i];

    if(array[n-1] == 0) for(int i = 1; i <= m; i++) dp[i][n-1] = 1;
    else dp[array[n-1]][n-1] = 1;

    for(int i = n-2; i >= 0; i--){
        if(array[i] == 0){
            for(int j = 1; j <= m; j++){
                dp[j][i] = (dp[j+1][i+1] + dp[j][i+1] + dp[j-1][i+1]) MOD INF;
            }
        }else{
            dp[array[i]][i] = (dp[array[i]-1][i+1] + dp[array[i]][i+1] + dp[array[i]+1][i+1]) MOD INF;
        }
    }

    long long ans = 0;
    for(int i = 1; i <= m; i++) ans += dp[i][0] MOD INF;
    cout << ans MOD INF << endl;

    return 0;
}