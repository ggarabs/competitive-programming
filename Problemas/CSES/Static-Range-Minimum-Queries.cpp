#include <bits/stdc++.h>
#define MAXN 200007
#define INF 1000000007

using namespace std;

int values[MAXN], segTree[4*MAXN];

void build(int node, int l, int r){
    if(l == r){
        segTree[node] = values[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    segTree[node] = min(segTree[2*node], segTree[2*node+1]);
}

int query(int node, int l, int r, int ql, int qr){
    if(qr < l || ql > r) return INF;

    if(ql <= l && qr >= r) return segTree[node];

    int mid = (l+r)/2;

    return min(query(2*node, l, mid, ql, qr), query(2*node+1, mid+1, r, ql, qr));
}

int main(){
    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> values[i];

    build(1, 1, n);

    while(q--){
        int a, b; cin >> a >> b;

        cout << query(1, 1, n, a, b) << endl;
    }

    return 0;
}