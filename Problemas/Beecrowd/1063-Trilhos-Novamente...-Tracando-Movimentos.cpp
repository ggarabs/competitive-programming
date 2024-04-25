#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	while(cin >> t && t){
		vector <char> entrada(t, '-'), saida(t, '-');
		stack <char> aux;
		for(int i = 0; i < t; i++) cin >> entrada[i];
		for(int i = 0; i < t; i++) cin >> saida[i];

		bool removed = false;

		for(int i = 0, j = 0; i < t;){
			while(j < t && saida[i] != entrada[j]){
				aux.push(entrada[j]);
				cout << "I";
				j++;
			}

			if(j < t && saida[i] == entrada[j]){
				aux.push(entrada[j]);
				cout << "I";
				j++;
			}

			removed = false;

			while(!aux.empty() && aux.top() == saida[i]){
				aux.pop();
				cout << "R";
				removed = true;
				i++;
			}

			if(!removed) break;
		}

		if(!removed) cout << " Impossible";

		cout << endl;
	}
	return 0;
}
