#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, m, ans = 0; cin >> n >> m;
        for(int i = 1; i <= m; i++) ans += (n/i + 1)/i;
        cout << --ans << endl;
    }
    return 0;
}