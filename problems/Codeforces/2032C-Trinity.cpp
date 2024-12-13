#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int ans = n;
		vector <int> a(n, 0), op(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());

		for(int i = 0; i < n-1; i++){
			int sum = a[i] + a[i+1];

			auto lb = lower_bound(a.begin(), a.end(), sum);

			op[i] = n-(lb - a.begin())+i;

			ans = min(ans, op[i]);
		}

		cout << ans << endl;

	}
	return 0;
}
