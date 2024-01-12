#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	set <string> capturados;

	for(int i = 0; i < n; i++){
		string nome;
		cin >> nome;
		capturados.insert(nome);
	}

	cout << "Falta(m) " << 151-capturados.size() << " pomekon(s)." << endl;

	return 0;
}
