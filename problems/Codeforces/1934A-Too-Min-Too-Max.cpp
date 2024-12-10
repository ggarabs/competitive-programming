#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector <int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        cout << abs(a[0]-a[n-1]) + abs(a[n-1]-a[1]) + abs(a[1]-a[n-2]) + abs(a[n-2]-a[0]) << endl;
    }
    return 0;
}