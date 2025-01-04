#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> target(n+1, 0), in(n+1, 0);
		for(int i = 1; i <= n; i++){
			cin >> target[i];
			in[target[i]]++;
		}

		int ans = 2, i = 0;
		vector<int> spiders;
		for(int i = 1; i <= n; i++) if(!in[i]) spiders.push_back(i);

		while(i < spiders.size()){
			int size = spiders.size();
			for(; i < size; i++){
				in[target[spiders[i]]]--;
				if(!in[target[spiders[i]]]) spiders.push_back(target[spiders[i]]);
			}
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}
