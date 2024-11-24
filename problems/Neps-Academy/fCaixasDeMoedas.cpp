#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

long long segtree[4*MAXN], lazy[4*MAXN], vet[MAXN];

void build(int node, int ql, int qr){
    if(ql==qr){
        segtree[node]=vet[ql];
        return;
    }
    
    int mid = (ql+qr)/2;

    build(2*node,ql,mid);
    build(2*node+1,mid+1,qr);

    segtree[node] = segtree[2*node] + segtree[2*node+1];
}

void update(int node, int l, int r, int a, int b, ll v){
    if(lazy[node] != -1){
        segtree[node] = (ll)lazy[node]*(r-l+1);

        if(l != r) lazy[2*node] = lazy[2*node+1] = lazy[node];

        lazy[node] = -1;
    }

    if(l > r || a > r || b < l) return;

    if(a <= l && r <= b){
        segtree[node] = (ll)v*(r-l+1);

        if(l != r) lazy[2*node] = lazy[2*node+1] = v;
    }else{
        int mid = (l+r)/2;

        update(2*node, l, mid, a, b, v);
        update(2*node+1, mid+1, r, a, b, v);

        segtree[node] = segtree[2*node] + segtree[2*node+1];
    }
}

ll query(int node, int l, int r, int a, int b){
    if(lazy[node] != -1){
        segtree[node] = lazy[node]*(r-l+1);

        if(l != r) lazy[2*node] = lazy[2*node+1] = lazy[node];

        lazy[node] = -1;
    }

    if(l > r || a > r || b < l) return 0;

    int mid = (l+r)/2;

    if(a <= l && r <= b) return segtree[node];
    else return query(2*node, l, mid, a, b) + query(2*node+1, mid+1, r, a, b);
}

int main(){ _
    int n, q; cin >> n >> q;

    memset(lazy, -1, sizeof(lazy));

    for(int i = 1; i <= n; i++) cin >> vet[i];

    build(1, 1, n);

    while(q--){
        int op, a, b; cin >> op >> a >> b;
        if(op == 1){
            int k; cin >> k;
            update(1, 1, n, a, b, k);
        }else{
            cout << (ll)query(1, 1, n, a, b) << endl;
        }
    }

    exit(0);
}
