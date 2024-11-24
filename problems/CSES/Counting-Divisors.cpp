#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    while(n--){
        int x, i, cont = 0; cin >> x;

        for(i = 1; i*i < x; i++) if(x % i == 0) cont += 2;
        
        if(i*i == x) cont++;

        cout << cont << endl;
    }

    return 0;
}