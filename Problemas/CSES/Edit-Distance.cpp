#include <bits/stdc++.h>
#define MAXN 5007

using namespace std;

int dp[MAXN][MAXN];

int main(){
    string a, b; cin >> a >> b;

    for(int i = 1; i <= (int)a.size(); i++) dp[i][0] = i;
    for(int i = 1; i <= (int)b.size(); i++) dp[0][i] = i;

    for(int i = 1; i <= (int)a.size(); i++){
        for(int j = 1; j <= (int)b.size(); j++){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
        }
    }

    cout << dp[(int)a.size()][(int)b.size()] << endl;

    return 0;
}