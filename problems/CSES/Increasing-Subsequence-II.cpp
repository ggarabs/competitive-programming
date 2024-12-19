#include <bits/stdc++.h>
#define lli long long int

const int MAXN = 2*1e5;
const int MOD = 1e9 + 7;

using namespace std;

lli dp[MAXN], seg[4*MAXN];

lli query(int node, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr) return seg[node];

    if(r < ql || qr < l) return 0;

    int mid = (l+r)/2;

    return query(2*node+1, l, mid, ql, qr) + query(2*node+2, mid+1, r, ql, qr);
}

void update(int node, int l, int r, int idx, lli v){
    if(l == r){
        seg[node] = v;
        return;
    }

    int mid = (l+r)/2;
    if(l <= idx && idx <= mid) update(2*node+1, l, mid, idx, v);
    else update(2*node+2, mid+1, r, idx, v);

    seg[node] = seg[2*node+1] + seg[2*node+2];
}

int main(){
    int n; cin >> n;

    vector <int> x(n, 0), sorted_x;

    for(int i = 0; i < n; i++){
        cin >> x[i];
        sorted_x.push_back(x[i]);
    }

    sort(sorted_x.begin(), sorted_x.end());

    map <int, int> mp;

    for(int i = 0; i < n; i++) mp[sorted_x[i]] = i+1;
    for(int i = 0; i < n; i++) x[i] = mp[x[i]];

    for(int i = 0; i < n; i++){
        dp[x[i]] = (dp[x[i]] + query(1, 1, n, 1, x[i]-1) + 1) % MOD;
        update(1, 1, n, x[i], dp[x[i]]);
    }

    cout << query(1, 1, n, 1, n) % MOD << endl;

    return 0;
}