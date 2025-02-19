#include <bits/stdc++.h>

using namespace std;

int main(){
    string a, b; cin >> a >> b;

    int cont = 0;

    for(int i = 0; i <= a.size()-b.size(); i++){
        bool sol = true;
        for(int j = 0; j < b.size(); j++){
            if(a[j+i] == b[j]){
                sol = false;
                break;
            }
        }
        cont += sol;
    }
    
    cout << cont << endl;

    return 0;
}