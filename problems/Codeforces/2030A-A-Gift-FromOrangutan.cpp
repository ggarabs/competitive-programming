#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;

		int minv = 1001, maxv = 0;

		for(int i = 0; i < n; i++){
			int a; cin >> a;
			minv = min(minv, a);
			maxv = max(maxv, a);
		}

		cout << (maxv-minv)*(n-1) << endl;

	}
	return 0;
}
