#include <bits/stdc++.h>

using namespace std;

int main(){
	int v, contas[3];
	cin >> v;

	for(int i = 0; i < 3; i++) cin >> contas[i];

	sort(contas, contas+3);

	int cont = 0;

	for(int i = 0; i < 3; i++){
		if(v - contas[i] < 0) break;
		cont++;
		v -= contas[i];
	}

	cout << cont << endl;

	return 0;
}
