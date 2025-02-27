#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k, p; cin >> n >> k >> p;

        double ans;
        if(k >= 0) ans = (int)ceil((double)k/abs(p));
        else ans = (int)floor((double)k/abs(p));

        if(abs(ans) > n){
            cout << -1 << endl;
            continue;
        }
        cout << abs(ans) << endl;
    }
    return 0;
}