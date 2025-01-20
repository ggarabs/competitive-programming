#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector <int> a(n, 0);

        for(int i = 0; i < n; i++) cin >> a[i];

        bool has_sol = true;

        for(int i = 0; i < n-1; i++){
            int x = a[i], y = a[i+1];
            a[i] -= min(x, y);
            a[i+1] -= min(x, y);
            if(a[i] > a[i+1]){
                has_sol = false;
                break;
            }
        }

        cout << (has_sol ? "YES" : "NO") << endl;
    }
    return 0;
}