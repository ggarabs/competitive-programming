#include <bits/stdc++.h>
#define MAXN 100107

using namespace std;

int main(){
	int n, k; cin >> n >> k;
	int a[MAXN], b[MAXN], c[MAXN];

	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = n-1; i >= 1; i--) c[i] = a[i] - a[i-1];
	c[0] = a[0];

	priority_queue <int> fila;
	int ans = 0;

	for(int i = 0; i < n; i++){
		if(k < a[i]){
			if(!fila.empty()){
				k = fila.top();
				if(k - a[i] < 0){
					cout << -1 << endl;
					return 0;
				}
				fila.pop();
				ans++;
			}
		}
		fila.push(b[i]+a[i]);
	}

	cout << ans << endl;

	return 0;
}
