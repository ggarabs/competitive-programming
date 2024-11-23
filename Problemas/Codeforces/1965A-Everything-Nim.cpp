#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		set <int> piles;
		for(int i = 0; i < n; i++){
			int aux; cin >> aux;
			piles.insert(aux);
		}
		if(piles.size() % 2 == 0) cout << "Bob" << endl;
		else cout << "Alice" << endl;
	}
	return 0;
}
