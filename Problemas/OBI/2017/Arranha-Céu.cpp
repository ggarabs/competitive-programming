#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int BIT[MAXN], n;

void mudanca(int ind, int valor){
    while(ind <= n){
        BIT[ind] += valor;
        ind += ind & (-ind);
    }
}

int bombeiro(int ind){
    int aux = 0;
    while(ind > 0){
        aux += BIT[ind];
        ind -= ind & (-ind);
    }
    return aux;
}

int main(){
    int q, andar[MAXN];
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> andar[i];
        mudanca(i, andar[i]);
    }

    for(int i = 0; i < q; i++){
        int op, k, p;
        cin >> op >> k;

        if(op == 0){
            cin >> p;
            mudanca(k, p-andar[k]);
            andar[k] = p;
        }else{
            cout << bombeiro(k);
        }
    }

    return 0;
}