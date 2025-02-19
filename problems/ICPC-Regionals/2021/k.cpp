#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, d, m; cin >> t >> d >> m;
    int time = 0;
    for(int i = 0; i < m; i++){
        int aux; cin >> aux;
        if(aux - time >= t){
            cout << "Y" << endl;
            return 0;
        }
        time = aux;
    }
    if(d - time >= t) cout << "Y" << endl;
    else cout << "N" << endl;
    
    return 0;
}