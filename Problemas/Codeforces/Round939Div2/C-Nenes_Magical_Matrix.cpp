#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, ans = 0; cin >> n;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) ans += max(i, j);
        cout << ans << " " << 2*n << endl;
        for(int i = n; i >= 1; i--){
            cout << 1 << " " << i << " ";
            for(int j = 1; j <= n; j++) cout << j << " ";
            cout << endl;
            cout << 2 << " " << i << " ";
            for(int j = 1; j <= n; j++) cout << j << " ";
            cout << endl;
        }
    }
    return 0;
}