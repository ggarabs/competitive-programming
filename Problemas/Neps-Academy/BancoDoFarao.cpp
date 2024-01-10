#include <bits/stdc++.h>

using namespace std;

#define MAXN 100007
#define INF 0x3f3f3f3f
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int seq[MAXN];

struct Cont {
    long long int val, cont;

    bool operator < (const Cont& b) const {
        const Cont& a = *this;

        if(a.val == b.val) return a.cont < b.cont;
        return a.val < b.val;
    }    

    Cont operator + (const Cont& b) const {
        const Cont& a = *this;
        
        return {a.val + b.val, a.cont + b.cont};
    }
};

struct Node {
    Cont sum, pref, suf, ans;

    Node operator + (const Node& b) const {
        const Node& a = *this;
        Node res;

        res.sum = a.sum + b.sum;
        res.pref = max(a.pref, a.sum+b.pref);
        res.suf = max(b.suf, b.sum+a.suf);
        res.ans = max({a.ans, b.ans, a.suf+b.pref});

        return res;
    }
};

Node segtree[4*MAXN];

void build(int node, int l, int r){
    if(l == r){
        segtree[node] = {{seq[l], 1}, {seq[l], 1}, {seq[l], 1}, {seq[l], 1}};
        return;
    }

    int mid = (l+r)>>1;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    segtree[node] = segtree[2*node] + segtree[2*node+1];
}

Node query(int node, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return segtree[node];
    }

    if(ql > r || l > qr){
        Node aux; aux.sum = aux.suf = aux.pref = aux.ans = {-INF, -INF};
        return aux;
    }

    int mid = (l+r)/2;

    return query(2*node, l, mid, ql, qr) + query(2*node+1, mid+1, r, ql, qr);
}

int main(){ _
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        for(int i = 1; i <= n; i++) cin >> seq[i];

        build(1, 1, n);

        int q; cin >> q;
        while(q--){
            int a, b;
            cin >> a >> b;

            Node res = query(1, 1, n, a, b);

            cout << res.ans.val << " " << res.ans.cont << endl;
        }
    }

    return 0;
}