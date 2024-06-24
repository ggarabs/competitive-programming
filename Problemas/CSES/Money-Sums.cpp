#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

bool dp[MAXN];

int main(){
    int n; cin >> n;

    vector <int> coin(n, 0);
    for(int i = 0; i < n; i++) cin >> coin[i];

    sort(coin.begin(), coin.end());

    dp[0] = 1;
    int maxv = 0, ans = 0;

    for(int i = n-1; i >= 0; i--){
        for(int j = maxv; j >= 0; j--){
            if(dp[j]){
                if(!dp[j+coin[i]]){ 
                    dp[j+coin[i]] = 1; 
                    ans++;
                }
                maxv = max(maxv, j+coin[i]);
            }
        }
    }

    cout << ans << endl;

    for(int i = 1; i <= maxv; i++) if(dp[i]) cout << i << " ";
    cout << endl;

    return 0;
}