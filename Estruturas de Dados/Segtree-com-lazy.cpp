#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int lazy[4*MAXN], segtree[4*MAXN], vet[MAXN];

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

void update(int node, int l, int r, int a, int b, int v){
    if(lazy[node]){ // existem operações atrasadas
        segtree[node] += lazy[node]*(r - l + 1); // adicionar lazy[node] varias vezes pra cada folha

        if(l != r){ // se i != j, há descendentes e temos que atualizar o valor de lazy deles
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }

        lazy[node] = 0; // não há valores atrasados no lazy desse nó
    }

    if(l > r || l > b || r < a) return;

    if(a <= l && r <= b){ // se a operação cobre o nó inteiro
        segtree[node] += v*(r - l + 1);

        if(l != r){ // se houver filhos, atualiza o lazy deles
            lazy[2*node] += v;
            lazy[2*node+1] += v;
        }

    }else{
        int mid = (l+r)/2;

        update(2*node, l, mid, a, b, v);
        update(2*node+1, mid+1, r, a, b, v);

        segtree[node] = segtree[2*node] + segtree[2*node+1];
    }
}

int query(int node, int l, int r, int ql, int qr){
    if(lazy[node]){
        segtree[node] += lazy[node]*(r - l + 1);

        if(l != r){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if(l > r || l > qr || r < ql) return 0;

    int mid = (l+r)/2;

    if(ql <= l && r <= qr) return segtree[node];
    else return query(2*node, l, mid, ql, qr) + query(2*node+1, mid+1, r, ql, qr);

}
