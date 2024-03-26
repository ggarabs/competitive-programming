#include <bits/stdc++.h>
#define MAXN 200007

using namespace std;

int main(){
	int n, q; cin >> n >> q;
	long long prefix_sum[MAXN]; prefix_sum[0] = 0;

	for(int i = 1; i <= n; i++){
		int x; cin >> x;
		prefix_sum[i] = x + prefix_sum[i-1];
	}

	for(int i = 0; i < q; i++){
		int a, b; cin >> a >> b;
		cout << prefix_sum[b] - prefix_sum[a-1] << endl;
	}

	return 0;
}
