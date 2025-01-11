#include <bits/stdc++.h>
#define lli long long int

const int MAXN = 2*1e5+7;
const lli INF = 2*1e10+7;

using namespace std;

struct Node {
    lli min1, min2, max1, max2, ans1, ans2;

    Node operator + (const Node &b) const {
        const Node &a = *this;
        Node res;

        res.min1 = min(a.min1, b.min1);
        res.min2 = min(a.min2, b.min2);
        res.max1 = max(a.max1, b.max1);
        res.max2 = max(a.max2, b.max2);
        res.ans1 = max({a.ans1, b.ans1, b.max1-a.min1});
        res.ans2 = max({a.ans2, b.ans2, a.max2-b.min2});

        return res;
    }
};

Node segtree[4*MAXN];

void build(int node, int l, int r, vector<pair<int, int>> &v){
    if(l == r){
        segtree[node] = {v[l].first, v[l].second, v[l].first, v[l].second, 0, 0};
        return;
    }

    int mid = (l+r)>>1;

    build(2*node, l, mid, v);
    build(2*node+1, mid+1, r, v);

    segtree[node] = segtree[2*node] + segtree[2*node+1];
}

void update(int node, int l, int r, int idx, int v){
    if(l == r){
        int aux1 = segtree[node].min1, aux2 = segtree[node].min2;
        segtree[node] = {aux1+v, aux2+v, aux1+v, aux2+v, 0, 0};
        return;
    }

    int mid = (l+r)>>1;

    if(l <= idx && idx <= mid) update(2*node, l, mid, idx, v);
    else update(2*node+1, mid+1, r, idx, v);

    segtree[node] = segtree[2*node] + segtree[2*node+1];
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;

        vector <pair<int, int>> a(n+1, {0, 0});
        vector <int> v(n+1, 0);

        for(int i = 1; i <= n; i++){
            cin >> v[i];
            a[i] = {v[i]-i, v[i]-(n-i)};
        }

        build(1, 1, n, a);

        cout << max(segtree[1].ans1, segtree[1].ans2) << endl;

        for(int i = 0; i < q; i++){
            int p, x; cin >> p >> x;

            update(1, 1, n, p, x-v[p]);
            v[p] = x;

            cout << max(segtree[1].ans1, segtree[1].ans2) << endl;
        }

        for(int i = 0; i <= 4*n; i++) segtree[i] = {INF, INF, 0, 0, 0, 0};
    }
    return 0;
}