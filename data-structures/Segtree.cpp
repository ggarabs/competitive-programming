// Segment tree
// build: O(n)
// Update: O(qlog n)
// query: O(qlog n)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int vet[maxn], tree[4*maxn];

void build(int node, int ql, int qr){
    if(ql==qr){
        tree[node]=vet[ql];
        return;
    }
    
    int mid = (ql+qr)/2;

    build(2*node+1,ql,mid);
    build(2*node+2,mid+1,qr);

    tree[node] = tree[2*node+1] + tree[2*node+2];
}

void update(int node, int l, int r, int idx, int v){
    if(l==r){
        tree[node]=v;
        return;
    }
    int mid = (l+r)/2;

    if(l<=idx && idx<=mid) update(2*node+1,l,mid,idx,v);
    else update(2*node+2,mid+1,r,idx,v);

    tree[node] = tree[2*node+1] + tree[2*node+2];
}

int query(int node, int l, int r, int ql, int qr){

    if(qr<l || ql>r) return 0;

    if(ql<=l && qr>=r) return tree[node];

    int mid = (l+r)/2;

    return query(2*node+1, l, mid, ql, qr)+query(2*node+2, mid+1, r, ql, qr);
}