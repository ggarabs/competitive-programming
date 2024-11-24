#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;

		vector <int> qtd(n+1, 0);
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			qtd[x]++;
		}

		bool victory = false;

		for(int i = 1; i <= n; i++) if(qtd[i]%2) victory = true;
		cout << (victory ? "YES" : "NO") << endl;
	}
	return 0;
}
