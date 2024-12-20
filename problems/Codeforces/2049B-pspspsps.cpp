#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string ps; cin >> ps;

        bool p = false, s = false;
        bool ans = true;

        for(int i = 0; i < n; i++){
            if(ps[i] == 'p') p = true;
            else if(ps[i] == 's'){
                if(p){
                    ans = false;
                    break;
                }
            }
        }

        bool dif = false;
        char letter = '.';

        for(int i = 1; i < n-1; i++){
            if(ps[i] == '.') continue;
            if(letter == '.'){
                letter = ps[i];
            }else{
                if(ps[i] != letter) ans = false;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}