#include <bits/stdc++.h>
#define MAXN 600000

using namespace std;

int dp[MAXN];
int posto[MAXN];

int pot(int x){
    int aux = 1;
    for(int i = 1; i <= x; i++) aux *= 2;
    return aux;
}

int main(){
    int n; cin >> n;

    for(int i = 1; i <= pot(n)-1; i++) cin >> posto[i];

    dp[0] = 0;

    int ans = 0;

    for(int i = 0; i <= pot(n)-1; i++){
        dp[2*i] = max(posto[2*i] + dp[i], dp[2*i]);
        dp[2*i+1] = max(posto[2*i+1] + dp[i], dp[2*i+1]);
        ans = max(ans, max(dp[2*i], dp[2*i+1]));
    }

    cout << ans << endl;
}
