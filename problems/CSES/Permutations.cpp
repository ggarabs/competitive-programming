#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    if(n > 1 && n < 4) cout << "NO SOLUTION" << endl;
    else{
        for(int i = 0, cont = 2; i < n; i++, cont += 2){
            if(cont > n) cont = 1;
            cout << cont << " ";
        }
        cout << endl;
    }

    return 0;
}