#include <bits/stdc++.h>
#define MAXN 1007
#define MOD %
#define INF 1000000007

using namespace std;

int dp[MAXN][MAXN];

int main(){
    int n;
    cin >> n;

    char map[MAXN][MAXN];

    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> map[i][j];

    if(map[1][1] == '*'){
        cout << 0 << endl;
        return 0;
    }

    memset(dp, 0, sizeof(dp));

    dp[1][1] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(map[i][j] != '*'){
                if(i == 1 && j == 1) continue;
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) MOD INF;
            }
        }
    }

    cout << dp[n][n] << endl;

    return 0;
}