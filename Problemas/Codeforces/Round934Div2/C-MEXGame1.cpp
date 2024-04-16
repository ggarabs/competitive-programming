#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector <int> values, solve;
		for(int i = 0; i < n; i++){
			int aux; cin >> aux;
			values.push_back(aux);
		}
		sort(values.begin(), values.end());
		int ans = -1, i;
		for(i = 0; i < n; i+=2){
			ans++;
			if(values[i] == ans && (i == n-1 || i == n-2)){
				ans++;
				break;
			}
			if(values[i] != ans){
				break;
			}
		}

		cout << ans << endl;
	}
}
