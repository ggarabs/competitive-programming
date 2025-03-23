#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

bool esta[MAXN];

int main(){
    int n; cin >> n;
    vector <int> fila(n, 0);

    for(int i = 0; i < n; i++){
        cin >> fila[i];
        esta[fila[i]] = 1;
    }

    int m; cin >> m;

    for(int i = 0; i < m; i++){
        int saiu; cin >> saiu;
        esta[saiu] = 0;
    }

    bool first = 1;

    for(int i = 0; i < n; i++){
        if(!first && esta[fila[i]]) cout << " ";
        if(esta[fila[i]]){
            cout << fila[i];
            first = 0;
        }
    }

    cout << endl;

    return 0;
}