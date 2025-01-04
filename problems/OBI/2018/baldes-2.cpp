#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

struct Node {
    int minv, maxv, ans;

    Node operator + (const Node &b) const {
        const Node &a = *this;
        
        Node res = {
            min(a.minv, b.minv),
            max(a.maxv, b.maxv),
            max({a.ans, b.ans, abs(a.maxv-b.minv), abs(a.minv-b.maxv)})
        };

        return res;
    }
};

int baldes[MAXN];
Node segtree[4*MAXN];

void build(int node, int l, int r){
    if(l == r){
        segtree[node].minv = baldes[l];
        segtree[node].maxv = baldes[l];
        segtree[node].ans = 0;
        return;
    }

    int mid = (l+r)>>1;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    segtree[node] = segtree[2*node] + segtree[2*node+1];
}

void update(int node, int l, int r, int idx, int nv){
    if(l == r){
        segtree[node].maxv = max(segtree[node].maxv, nv);
        segtree[node].minv = min(segtree[node].minv, nv);
        return;
    }
    int mid = (l+r)>>1;

    if(idx <= mid) update(2*node, l, mid, idx, nv);
    else update(2*node+1, mid+1, r, idx, nv);

    segtree[node] = segtree[2*node] + segtree[2*node+1];
}

Node query(int node, int l, int r, int ql, int qr){
    if(qr < l || r < ql) {
        return {0, 0, 0};
    }

    if(ql <= l && r <= qr) return segtree[node];

    int mid = (l+r)>>1;

    if(qr <= mid) return query(2*node, l, mid, ql, qr);
    if(ql > mid) return query(2*node+1, mid+1, r, ql, qr);

    Node aux = query(2*node, l, mid, ql, qr) + query(2*node+1, mid+1, r, ql, qr);

    return aux;
}

int main(){
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> baldes[i];

    build(1, 1, n);

    for(int i = 0; i < m; i++){
        int op, a, b; cin >> op >> a >> b;
        if(op == 1) update(1, 1, n, b, a); 
        else cout << query(1, 1, n, a, b).ans << endl;
    }

    return 0;
}