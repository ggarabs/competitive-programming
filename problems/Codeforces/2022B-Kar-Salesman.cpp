#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, x; cin >> n >> x;
		long long int sum = 0, maxv = 0;
		for(int i = 0; i < n; i++){
			long long int ai; cin >> ai;
			sum += ai;
			maxv = max(maxv, ai);
		}

		cout << max(maxv, (long long int)ceil((double)sum/x)) << endl;
	}
	return 0;
}
