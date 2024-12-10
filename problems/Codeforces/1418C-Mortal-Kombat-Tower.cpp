#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> a(n+1, 0);
        cin >> a[0];
        int seg = 0, ans = a[0];
        for(int i = 1; i < n; i++){
            cin >> a[i];
            if(a[i]) seg++;
            else{
                ans += seg/3;
                seg = 0;
            }
        }
        if(seg > 0) ans += seg/3;
        cout << ans << endl;
    }

    return 0;
}