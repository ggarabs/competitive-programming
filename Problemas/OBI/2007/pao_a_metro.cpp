#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int n, k, maxv;
vector <int> tam;

int busca_binaria(int n){
    int ini = 1, fim = maxv, meio;

    while(ini <= fim){
        meio = (ini+fim)/2;
        int pedacos = 0;

        for(int i = 0; i < tam.size(); i++) pedacos += tam[i]/meio;

        if(pedacos >= n) ini = meio + 1;
        else fim = meio - 1;
    }

    return fim;
}

int main(){
    cin >> n >> k;

    for(int i = 0; i < k; i++){
        int comp;
        cin >> comp;
        tam.pb(comp);
        maxv = max(maxv, tam[i]);
    }

    cout << busca_binaria(n) << endl;

    return 0;
}