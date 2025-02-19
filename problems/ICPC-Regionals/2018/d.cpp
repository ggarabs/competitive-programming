#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    int uns = 0;
    for(int i = 0; i < n; i++){
        int porta; cin >> porta;
        if(porta == 1) uns++;
    }

    cout << n-uns << endl;

    return 0;
}