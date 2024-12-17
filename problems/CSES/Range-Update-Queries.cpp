#include <bits/stdc++.h>
#define lli long long int
#define MAXN 200007

using namespace std;

lli tree[4*MAXN], vet[MAXN], diff[MAXN];

void build(int node, int ql, int qr){
	if(ql == qr){
		tree[node] = diff[ql];
		return;
	}

	int mid = (ql+qr)/2;

	build(2*node, ql, mid);
	build(2*node+1, mid+1, qr);

	tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int node, int l, int r, int idx, int v){
	if(l == r){
		tree[node] += v;
		return;
	}

	int mid = (l+r)/2;

	if(l <= idx && idx <= mid) update(2*node, l, mid, idx, v);
	else update(2*node+1, mid+1, r, idx, v);

	tree[node] = tree[2*node] + tree[2*node+1];
}

lli query(int node, int l, int r, int idx){
	if(idx < l || 1 > r) return 0;

	if(1 <= l && r <= idx){
		return tree[node];
	}

	int mid = (l+r)/2;

	return query(2*node, l, mid, idx) + query(2*node+1, mid+1, r, idx);
}

int main(){
	int n, q; cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> vet[i];
		diff[i] = vet[i]-vet[i-1];
	}
	build(1, 1, n);

	for(int i = 0; i < q; i++){
		int op; cin >> op;
		if(op == 1){
			int a, b, u; cin >> a >> b >> u;
			if(b <= n-1) update(1, 1, n, b+1, -u);
			update(1, 1, n, a, u);		
		}else{
			int k; cin >> k;
			cout << query(1, 1, n, k) << endl;
		}
	}

	return 0;
}
