#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    string w1, w2;

    cin >> n >> w1 >> m >> w2;

    int u = 0, d = 0, ans = 0;

    while(u < w1.size() && d < w2.size() && w1[u++] == w2[d++]) ans++;

    cout << ans << endl;

    return 0;
}