#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, h;
    cin >> n >> h;

    int ans = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(h >= x) ans++;
    }

    cout << ans << endl;

    return 0;
}