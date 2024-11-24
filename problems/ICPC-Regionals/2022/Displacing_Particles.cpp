#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x_dest, y_dest;
	cin >> n >> x_dest >> y_dest;

	int atual, ini = 0, fim = pow(2, n), cont_x = 0;

	while(ini <= fim){
		atual = (ini+fim)/2;
		cont_x++;

		if(atual == x_dest) break;
		else if(atual > x_dest) fim = atual;
		else ini = atual;
	}

	cout << cont_x-1 << endl;

	return 0;
}