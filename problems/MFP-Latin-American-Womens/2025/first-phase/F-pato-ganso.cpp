#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, p, k; cin >> n >> p >> k;

    n--, p--, k++; k %= n;

    if(k == 0) k = n;

    int ans = k+p+1;
    if(ans > n+1) ans -= n+1;

    cout << ans << endl;

    return 0;
}