#include <bits/stdc++.h>

using namespace std;

int main(){
	map <int, double> dic;
	double aux = 1.5;

	for(int i = 1001; i <= 1005; i++){
		dic[i] = aux;
		aux++;
	}

	int p;
	cin >> p;

	double ans = 0;

	for(int i = 0; i < p; i++){
		int x, qtd;
		cin >> x >> qtd;
		ans += qtd*dic[x];
	}

	cout.precision(2);
	cout.setf(ios::fixed);

	cout << ans << endl;

	return 0;
}
