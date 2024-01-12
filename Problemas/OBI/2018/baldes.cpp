#include <bits/stdc++.h>
#define MAXN 100007
#define INF 9999999

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef pair<int, int> pii;

pii segtree[4*MAXN], tree[4*MAXN], aux_v;
int seq[MAXN];

void build(int node, int l, int r){
    if(l == r){
        segtree[node]=pii(seq[l], seq[l]);
        tree[node]=pii(l, r);
        return;
    }

    int mid=(l+r)>>1;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    segtree[node] = {min(segtree[2*node].first, segtree[2*node+1].first), max(segtree[2*node].second, segtree[2*node+1].second)};
    tree[node].first = segtree[node].first == segtree[2*node].first ? tree[2*node].first : tree[2*node+1].first;
    tree[node].second = segtree[node].second == segtree[2*node].second ? tree[2*node].second : tree[2*node+1].second;
}

void update(int node, int l, int r, int pos, int nv, int mode){
    if(l == r){
        if(mode==0) segtree[node] = pii(min(segtree[node].first, nv), max(segtree[node].second, nv));
        else if(mode==1){
            aux_v = segtree[node];
            segtree[node] = pii(INF, -INF);
        }else segtree[node] = aux_v;
        return;
    }

    int mid = (l+r)>>1;

    if(l <= pos && pos <= mid) update(2*node, l, mid, pos, nv, mode);
    else update(2*node+1, mid+1, r, pos, nv, mode);

    segtree[node] = {min(segtree[2*node].first, segtree[2*node+1].first), max(segtree[2*node].second, segtree[2*node+1].second)};
    tree[node].first = segtree[node].first == segtree[2*node].first ? tree[2*node].first : tree[2*node+1].first;
    tree[node].second = segtree[node].second == segtree[2*node].second ? tree[2*node].second : tree[2*node+1].second;
}

pair <pii,pii> query(int node, int l, int r, int ql, int qr, int mode){
    if(qr < l || ql > r) return pair<pii, pii>(pii(INF, INF), pii(INF, -INF));

    if(ql <= l && r <= qr) return pair<pii, pii>(tree[node], segtree[node]);

    int mid = (l+r)/2;

    pair<pii, pii> filho1 = query(2*node, l, mid, ql, qr, mode), filho2 = query(2*node+1, mid+1, r, ql, qr, mode);

    if(mode) return (filho1.second.second >= filho2.second.second) ? filho1 : filho2;
    return (filho1.second.first <= filho2.second.first) ? filho1 : filho2;
}

int main(){ _
    
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> seq[i];

    build(1, 1, n);

    while(m--){
        int op, a, b; cin >> op >> a >> b;
        if(op == 1) update(1, 1, n, b, a, 0);
        else{
            int ans[2] = {0, 0};
            pair<pii, pii> min_v, max_v;

            min_v = query(1, 1, n, a, b, 0);
            update(1, 1, n, min_v.first.first, INF, 1);
            max_v = query(1, 1, n, a, b, 1);
            update(1, 1, n, min_v.first.first, INF, 2);

            ans[0] = max_v.second.second - min_v.second.first;

            max_v = query(1, 1, n, a, b, 1);
            update(1, 1, n, max_v.first.second, INF, 1);
            min_v = query(1, 1, n, a, b, 0);
            update(1, 1, n, max_v.first.second, INF, 2);

            ans[1] = max_v.second.second - min_v.second.first;

            cout << max(ans[0], ans[1]) << endl;
        }
    }

    return 0;
}