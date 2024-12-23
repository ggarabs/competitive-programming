#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> a(n, 0), b(n+1, 0);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        b[n] = 0;

        int ans = 0;

        for(int i = 0; i < n; i++){
            if(a[i]-b[i+1] > 0) ans += a[i]-b[i+1];
       }

       cout << ans << endl;
    }
}