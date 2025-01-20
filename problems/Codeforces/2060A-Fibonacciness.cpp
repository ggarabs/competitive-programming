#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a[5];
        for(int i = 0; i < 4; i++) cin >> a[i];

        set<int> x;

        x.insert(a[0]+a[1]);
        x.insert(a[2]-a[1]);
        x.insert(a[3]-a[2]);

        cout << 4 - x.size() << endl;
    }
}