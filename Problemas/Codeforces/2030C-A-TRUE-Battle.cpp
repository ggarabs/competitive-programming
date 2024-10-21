#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, cont = 0; cin >> n;
		string aux; cin >> aux;
		
		if(aux[0] == '1' || aux[aux.size()-1] == '1'){
			cout << "YES" << endl;
			continue;
		}

		bool win = false;

		for(int i = 0; i < aux.size()-1; i++){
			if(aux[i] == '1' && aux[i+1] == '1'){
				cout << "YES" << endl;
				win = true;
				break;
			}
		}

		if(!win) cout << "NO" << endl;

	}
	return 0;
}
