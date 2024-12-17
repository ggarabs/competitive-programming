#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int m, a, b, c, ans = 0; cin >> m >> a >> b >> c;
        int r1 = m, r2 = m;

        ans += min(m, a);
        r1 -= min(m, a);

        ans += min(m, b);
        r2 -= min(m, b);

        ans += min(r1+r2, c);

        cout << ans << endl;
    }
    return 0;
}