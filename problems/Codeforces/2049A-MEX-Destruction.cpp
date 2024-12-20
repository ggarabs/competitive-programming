#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> arr(n, 0);
        for(int i = 0; i < n; i++) cin >> arr[i];
        int l = 0, r = n-1;
        while(l < arr.size() && !arr[l]) l++;
        while(r > 0 && !arr[r]) r--;

        if(l > r){
            cout << 0 << endl;
            continue;
        }

        bool has_zero = false;

        for(int i = l; i <= r; i++) if(!arr[i]) has_zero = true;

        cout << (has_zero ? 2 : 1) << endl;

    }
    return 0;
}