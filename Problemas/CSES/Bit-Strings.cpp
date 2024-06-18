#include <bits/stdc++.h>
#define INF 1000000007

using namespace std;

int main(){
    int n; cin >> n;

    int ans = 1;

    for(int i = 1; i <= n; i++) ans = ((ans << 1) % INF);

    cout << ans << endl;

    return 0;
}