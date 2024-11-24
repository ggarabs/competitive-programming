#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string game; cin >> game;

        int n_u = 0;

        for(int i = 0; i < n; i++) if(game[i] == 'U') n_u++;

        if(n_u % 2 == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}