#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector <int> brands(k+1, 0);
        for(int i = 0; i < k; i++){
            int b, c; cin >> b >> c;
            brands[b] += c;
        }

        sort(brands.begin(), brands.end(), greater<int>());

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(brands[i] == 0) break;
            ans += brands[i];
        }

        cout << ans << endl;
    }
}