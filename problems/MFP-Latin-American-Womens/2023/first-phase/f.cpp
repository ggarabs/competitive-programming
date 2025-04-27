#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int p1 = 0, p2 = 0;

    vector <string> pontos;

    for(int i = 0; i < n; i++){
        char aux;
        for(int j = 0; j <= 4; j++){
            cin >> aux;
        }
        if(aux == '1'){
            for(int j = 0; j < 2; j++){
                cin >> aux;
            }
            p1 += aux - '0';
        }else{
            for(int j = 0; j < 2; j++){
                cin >> aux;
            }
            p2 += aux - '0';
        }
    }

    cout << p1 << " x " << p2 << endl;

    return 0;
}