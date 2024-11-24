#include <bits/stdc++.h>
#define MAXV 100007

using namespace std;

int main(){
    int n; cin >> n;

    int min_v = MAXV, row, col;

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        int aux; cin >> aux;
        if(aux < min_v){
            row = i; col = j; min_v = aux;
        }
    }

    if(row == 0 && col == 0) cout << 0;
    else if(col == 0) cout << 3;
    else if(row == 0) cout << 1;
    else cout << 2;

    cout << endl;

    return 0;
}