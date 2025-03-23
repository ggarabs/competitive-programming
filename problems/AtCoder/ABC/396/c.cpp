#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector <int> b(n, 0), w(m, 0);

    for(auto &x : b) cin >> x;
    for(auto &x : w) cin >> x;

    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());

    lli sum = 0;

    int itb = 0, ita = 0;
    for(; itb < n && b[itb] > 0; itb++) sum += b[itb];
    for(; ita < m && w[ita] > 0 && ita < itb; ita++) sum += w[ita];
    for(; ita < m && itb < n && w[ita]+b[itb] > 0; ita++, itb++) sum += b[itb] + w[ita];
    
    cout << sum << endl;

    return 0;
}