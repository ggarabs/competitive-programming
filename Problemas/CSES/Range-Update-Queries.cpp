#include <bits/stdc++.h>
#define lli long long int

const int MAXN = 200007;

using namespace std;

int arr[MAXN];
lli lazy[4*MAXN], segTree[4*MAXN];

void build(int node, int ql, int qr){
    if(ql == qr){
        segTree[node] = arr[ql];
        return;
    }

    int mid = (ql+qr)/2;

    build(2*node, ql, mid);
    build(2*node+1, mid+1, qr);

    segTree[node] = segTree[2*node] + segTree[2*node+1];
}

void update(int node, int l, int r, int a, int b, lli u){
    if(lazy[node]){
        segTree[node] += lazy[node]*(r - l + 1);

        if(r != l){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(l > r || b < l || r < a) return;

    if(a <= l && r <= b){
        segTree[node] += u*(r - l + 1);

        if(r != l){
            lazy[2*node] += u;
            lazy[2*node+1] += u;
        }
    }else{
        int mid = (l+r)/2;

        update(2*node, l, mid, a, b, u);
        update(2*node+1, mid+1, r, a, b, u);

        segTree[node] = segTree[2*node] + segTree[2*node+1];
    }
}

lli query(int node, int l, int r, int q){
    if(lazy[node]){
        segTree[node] += lazy[node]*(r - l + 1);

        if(l != r){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(l > r || q < l || r < q) return 0;

    int mid = (l+r)/2;

    if(q == l && q == r) return segTree[node];
    else if(l <= q && q <= mid) return query(2*node, l, mid, q);
    else return query(2*node+1, mid+1, r, q);
}

int main(){
    int n, q; cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> arr[i];

    build(1, 1, n);

    for(int i = 0; i < q; i++){
        char op; cin >> op;
        if(op == '1'){
            int a, b, u; cin >> a >> b >> u;

            update(1, 1, n, a, b, u);
        }else{
            int k; cin >> k;

            cout << query(1, 1, n, k) << endl;
        }
    }

    return 0;
}