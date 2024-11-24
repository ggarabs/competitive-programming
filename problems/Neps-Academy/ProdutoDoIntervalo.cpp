#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

char seq[MAXN], segtree[4*MAXN];

char op(char a, char b){
    if(a == '0' || b == '0') return '0';
    if(a != b) return '-';
    return '+';
}

void build(int node, int l, int r){
    if(l == r){
        segtree[node] = seq[l];
        return;
    }
    int mid = (l+r)/2;

    build(2*node, l, mid);
    build(2*node+1, mid+1, r);

    segtree[node] = op(segtree[2*node], segtree[2*node+1]);
}

void update(int node, int l, int r, int pos, char value){
    if(l == r){
        seq[pos] = value;
        segtree[node] = value;
        return;
    }

    int mid = (l+r)/2;

    if(l <= pos && pos <= mid) update(2*node, l, mid, pos, value);
    else update(2*node+1, mid+1, r, pos, value);

    segtree[node] = op(segtree[2*node], segtree[2*node+1]);
}

char query(int node, int l, int r, int ql, int qr){
    if(ql <= l && r <= qr){
        return segtree[node];
    }

    if(r < ql || l > qr){
        return '+';
    }

    int mid = (l+r)/2;

    return op(query(2*node, l, mid, ql, qr), query(2*node+1, mid+1, r, ql, qr));
}

int main(){
    int n, k;

    while(cin >> n >> k){
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            if(x > 0) seq[i] = '+';
            else if(x < 0) seq[i] = '-';
            else seq[i] = '0';
        }

        build(1, 1, n);

        for(int i = 1; i <= k; i++){
            char c; int k, l; cin >> c >> k >> l;

            if(c == 'C'){
                char nv = (l >= 0)?(l == 0?'0':'+'):'-';
                update(1, 1, n, k, nv);
            }else{
                cout << query(1, 1, n, k, l);
            }
        }
    
        cout << endl;
    }

    return 0;
}