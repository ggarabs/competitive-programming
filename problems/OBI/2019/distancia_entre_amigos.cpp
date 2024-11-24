#include <bits/stdc++.h>
#define MAXN 200007

using namespace std;

int main(){
    int n, altura[MAXN];
    cin >> n;

    altura[0]=0, altura[n+1]=0;
    for(int i = 1; i <= n; i++) cin >> altura[i];

    int ans = 0, aux = 0;

    for(int i = 1; i <= n; i++){
        ans = max(ans, aux+altura[i]);
        aux = max(aux, altura[i]);
        aux++;
    }

    cout << ans << endl;

    return 0;
}