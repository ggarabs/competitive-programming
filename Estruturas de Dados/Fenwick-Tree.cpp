#include <bits/stdc++.h>
#define MAXN 10007

using namespace std;

int BIT[MAXN];
int tam; // tamanho do vetor

void update(int ind, int value){
    for(; ind <= tam; ind += (ind & (-ind))){ // lsb(x) = x & -x;
        BIT[ind] += value;
    }
}

int sum(int ind){
    int aux = 0;
    while(ind > 0){
        aux += BIT[ind]; // Ex: sum(5) = BIT[5] + BIT[4]; sum(3) = BIT[3] + BIT[2];
        ind -= ind & (-ind); // lsb(x) = x & -x;
    }
    return aux;
}

int query(int l, int r){
    return sum(r) - sum(l-1);
}

int main(){
    int vetor[MAXN];
    cin >> tam;

    for(int i = 1; i <= tam; i++){
        cin >> vetor[i];
        update(i, vetor[i]);
    }

    cout << query(3, 5) << endl;
    update(2, 10);
    cout << query(2, 5) << endl;

    return 0;
}