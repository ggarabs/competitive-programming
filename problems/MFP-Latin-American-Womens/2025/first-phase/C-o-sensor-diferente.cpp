#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int k[3];
        int xorv;
        for(int i = 0; i < 3; i++){
            cin >> k[i];
            if(i == 0) xorv = k[i];
            else xorv ^= k[i];
        }
        cout << xorv << endl;
    }

    return 0;
}