#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int seq[MAXN];

struct Node {
    int sum, pref, suf, ans;
};

Node segtree[4*MAXN];

void build(int node, int l, int r){
    if(l == r){
        segtree[node] = {seq[l], seq[l], seq[l], seq[l]};
        return;
    }

    int mid = (l+r)>>1;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    segtree[node].sum = segtree[2*node].sum + segtree[2*node+1].sum;
    segtree[node].pref = max(segtree[2*node].pref, segtree[2*node].sum+segtree[2*node+1].pref);
    segtree[node].suf = max(segtree[2*node+1].suf, segtree[2*node+1].sum+segtree[2*node].suf);
    segtree[node].ans = max(max(segtree[2*node].ans, segtree[2*node+1].ans), segtree[2*node].suf+segtree[2*node+1].pref);
}

Node query(int node, int l, int r, int ql, int qr){ // mudar
    if(ql <= l && r <= qr){
        return node;
    }

    if(ql > r || l > qr){
        return 0;
    }

    int mid = (l+r)>>1;

    Node f1 = query(2*node, l, mid, ql, qr), f2 = query(2*node+1, mid+1, r, ql, qr);

    return max(max(f1.ans, f2.ans), f1.suf+f2.pref);
}

int main(){
    int n; cin >> n;

    for(int i = 1; i <= n; i++) cin >> seq[i];

    build(1, 1, n);

    int q; cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;

        cout << query(1, 1, n, a, b) << endl;
    }


    return 0;
}