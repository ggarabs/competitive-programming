#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int d, i, b; cin >> d >> i >> b;
		vector <int> ing(i, 0), bolos(b, 0);
		for(int k = 0; k < i; k++) cin >> ing[k];
		for(int k = 0; k < b; k++){
			int q; cin >> q;
			for(int j = 0; j < q; j++){
				int id, qtd; cin >> id >> qtd;
				bolos[k] += ing[id]*qtd;
			}
		}
		sort(bolos.begin(), bolos.end());
		cout << d/bolos[0] << endl;
	}
	return 0;
}
