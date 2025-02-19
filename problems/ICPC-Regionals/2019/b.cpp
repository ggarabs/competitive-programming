#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    n--;
    int carlos;
    cin >> carlos;

    while(n--){
        int aux; cin >> aux;
        if(aux > carlos){
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;

    return 0;
}