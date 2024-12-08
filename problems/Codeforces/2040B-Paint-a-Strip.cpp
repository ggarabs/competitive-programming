#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        int it = 1, ans = 0;

        while(it < n){
            ans++;
            it += (it+2);
        }

        cout << ans+1 << endl;

    }
    return 0;
}