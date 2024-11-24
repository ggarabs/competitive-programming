#include <bits/stdc++.h>
#define MAXN 10007
#define INF 1999999999

using namespace std;

int main(){
    int n, saldo[MAXN], it = 1;

    while(cin >> n){
        if(n == 0) break;
        saldo[0] = 0;
        for(int i = 1; i <= n; i++){
            int gp, gc;
            cin >> gp >> gc;
            saldo[i] = gp-gc;
        }

        int ans = -INF, parc = INF;

        for(int i = 1; i <= n; i++){
            parc = max(0, parc+saldo[i]);
            ans = max(ans, parc);
        }

        int p1 = 1, p2 = 1;
        parc = 0;

        for(int k = 1, i = 1, j = 1; k <= n, i <= n, j <= n;k++){
            parc = max(0, parc+saldo[k]);
            if(parc == 0){i++;j++;}
            else if(parc < ans) j++;
            else if(j-i > p2-p1){ p2=j; p1=i; }
        }

        cout << "Teste " << it << endl;
        if(ans < 0 || p1 > p2) cout << "nenhum" << endl;
        else cout << p1 << " " << p2 << endl;
        cout << endl;

        it++;
    }

    return 0;
}