#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int main(){
    int n, prefix_sum[MAXN], vetor[MAXN], pares[MAXN], impares[MAXN];
    cin >> n;

    prefix_sum[0] = vetor[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> vetor[i];
        prefix_sum[i] = prefix_sum[i-1]+vetor[i];
    }

    pares[n+1] = 0;
    impares[n+1] = 0;

    for(int i = n; i >= 0; i--){
        if(prefix_sum[i]%2==0){
            pares[i] = 1 + pares[i+1];
            impares[i] = impares[i+1];
        }else{
            pares[i] = pares[i+1];
            impares[i] = 1 + impares[i+1];
        }
    }

    long long int ans = 0;

    for(int i = 1; i <= n; i++){
        if(vetor[i] == 1){
            if(prefix_sum[i]%2 == 1) ans += impares[i];
            else ans += pares[i];
        }else{
            if(prefix_sum[i]%2 == 1) ans += pares[i];
            else ans += impares[i];
        }
    }

    cout << ans << endl;

    return 0;
}