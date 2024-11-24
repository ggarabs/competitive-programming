#include <bits/stdc++.h>

using namespace std;

int main(){
	char op; cin >> op;
	double matriz[12][12], soma = 0;
	int qtd = 0;

	for(int i = 0; i < 12; i++) for(int j = 0; j < 12; j++){
		cin >> matriz[i][j];
		if(i + j >= 12){
			soma += matriz[i][j];
			qtd++;
		}
	}

	cout.precision(1);
	cout.setf(ios::fixed);

	if(op == 'S') cout << soma << endl;
	else cout << soma/(double)qtd << endl;

	return 0;
}

