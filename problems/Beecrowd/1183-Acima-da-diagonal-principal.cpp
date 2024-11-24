#include <bits/stdc++.h>

using namespace std;

int main(){
    char op;
    cin >> op;

    float matriz[12][12];

    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            cin >> matriz[i][j];
        }
    }

    float soma = 0;

    for(int i = 0; i < 12; i++){
        for(int j = i + 1; j < 12; j++){
            soma += matriz[i][j];
        }
    }

    float media = soma/(66);

    if(op == 'S'){
        cout.precision(1);
        cout.setf(ios::fixed);
        cout << soma;
    }else{
        cout.precision(1);
        cout.setf(ios::fixed);
        cout << media;
    }
    
    cout << endl;

    return 0;

}
