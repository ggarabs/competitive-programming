#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		long long max_pot = 1;
		while(max_pot <= n){
			max_pot *= k;
			if(max_pot == 1) break;
		}
		max_pot /= k;

		int ans = 0;
		while(max_pot > 1){
			ans += n / max_pot;
			n %= max_pot;
			max_pot /= k;
		}

		ans += n;

		cout << ans << endl;
	}
	return 0;
}
