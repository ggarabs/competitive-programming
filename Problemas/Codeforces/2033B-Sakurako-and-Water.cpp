#include <bits/stdc++.h>
#define MAXN 507

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> minv((n+1)*(n+1), 0);

		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
			int pos; cin >> pos;
			minv[j-i+n-1] = min(minv[j-i+n-1], pos);
		}

		int ans = 0;
		for(int i = 0; i < minv.size(); i++) ans += minv[i];

		cout << -ans << endl;
	}
	return 0;
}
