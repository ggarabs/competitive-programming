#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    int ant = 1, atual = 1;

    for(int i = 0; i < n-1; i++){
        int aux = ant;
        ant = atual;
        atual = aux + ant;
    }

    cout << atual << endl;

    return 0;
}