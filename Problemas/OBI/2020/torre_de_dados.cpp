#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

int main(){
    int n;
    cin >> n;

    int dados[MAXN][7], pos[MAXN][7];
    int oposto[7] = {0, 6, 4, 5, 2, 3, 1};

    for(int i = 0; i < n; i++){
        for(int j = 1; j <= 6; j++){
            cin >> dados[i][j];
            pos[i][dados[i][j]] = j;
        }
    }

    int ans = 0, ordem[MAXN];
    for(int i = 0; i < n; i++) ordem[i] = i;

    do {
        for(int i = 1; i <= 6; i++){
            int ini = dados[ordem[0]][i], sum = 0;
            for(int j = 1; j <= n; j++){
                int op = dados[ordem[j-1]][oposto[pos[ordem[j-1]][ini]]];
                if(ini == 6 || op == 6){
                    if(ini == 5 || op == 5) sum += 4;
                    else sum += 5;
                }else sum += 6;
                ini = op;
            }
            ans = max(ans, sum);
        }
    } while(next_permutation(ordem, ordem+n));

    cout << ans << endl;

    return 0;
}