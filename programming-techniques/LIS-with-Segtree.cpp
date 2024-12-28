#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1e5+7;

int dp[MAXN], segtree[4*MAXN];

void update(int node, int l, int r, int idx, int v){
    if(l == r){
        segtree[node] = v;
        return;
    }
    int mid = (l+r)/2;

    if(l <= idx &&  idx <= mid) update(2*node+1, l, mid, idx, v);
    else update(2*node+2, mid+1, r, idx, v);

    segtree[node] = max(segtree[2*node], segtree[2*node+2]);
}

int query(int node, int l, int r, int ql, int qr){
    if(qr < l || ql > r) return 0;

    if(ql <= l && r <= qr) return segtree[node];

    int mid = (l+r)/2;

    return max(query(2*node+1, l, mid, ql, qr), query(2*node+2, mid+1, r, ql, qr));
}

int main(){
    int n; cin >> n;
    vector <int> a(n, 0), aux;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        aux.push_back(a[i]);
    }

    sort(aux.begin(), aux.end());

    map <int, int> mp;
    for(int i = 0; i < n; i++) if(!mp.count(aux[i])) mp[aux[i]] = i+1;

    for(int i = 0; i < n; i++){
        // cout << a[i] << endl << mp[a[i]] << endl << query(0, 0, n, 0, mp[a[i]]-1) << endl << endl;
        dp[mp[a[i]]] = max(query(0, 0, n, 0, mp[a[i]]-1)+1, dp[mp[a[i]]]);
        update(0, 0, n, mp[a[i]], dp[mp[a[i]]]);
    }

    for(int i = 0; i <= n; i++){
        cout << dp[mp[a[i]]] << endl;
    }

    return 0;
}