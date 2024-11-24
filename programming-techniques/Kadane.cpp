#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, vetor[50007];
    cin >> n;

    for(int i=0; i<n; i++) cin >> vetor[i];

    int soma_max = 0, ans = 0;

    for(int i=0; i<n; i++){
        soma_max = max(0, soma_max + vetor[i]);

        ans = max(soma_max, ans);
    }

    cout << ans;

    return 0;
}