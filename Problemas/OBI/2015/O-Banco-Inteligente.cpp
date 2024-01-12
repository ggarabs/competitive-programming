#include <bits/stdc++.h>
#define MAXN 5007

using namespace std;

int dp[MAXN];

int main(){
    int s, notas[] = {2, 5, 10, 20, 50, 100}, qtd[6];
    cin >> s;

    dp[0] = 1;

    for(int i = 0; i < 6; i++) cin >> qtd[i];

    for(int i = 0; i < 6; i++){
        for(int j = s-1; j >= 0; j--){
            if(dp[j] > 0) for(int k = 1; k <= qtd[i] && j+k*notas[i] <= s; k++) dp[j+k*notas[i]] += dp[j];
        }
    }

    cout << dp[s] << endl;

    return 0;
}