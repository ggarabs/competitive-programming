#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long int g[8], ans = 0, sum = 0;
    cin >> n;

    memset(g, 0, sizeof(g));

    g[0] = 1;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;

        sum += aux;
        ans += g[sum%8];
        g[sum%8]++;
    }

    cout << ans << endl;

    return 0;
}