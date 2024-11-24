#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		string a, b;
		cin >> a >> b;

		if(a.size() < b.size()){
			cout << "nao encaixa" << endl;
			continue;
		}

		bool encaixa = true;
		
		for(int j = a.size()-b.size(), k = 0; j < a.size() && k < b.size(); j++, k++){
			if(a[j] != b[k]){
				encaixa = false;
				break;
			}
		}

		if(encaixa) cout << "encaixa" << endl;
		else cout << "nao encaixa" << endl;
	}

	return 0;
}
