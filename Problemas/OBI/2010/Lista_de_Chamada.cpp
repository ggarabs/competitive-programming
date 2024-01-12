#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;

	set <string> lista;

	for(int i = 0; i < n; i++){
		string nome;
		cin >> nome;
		lista.insert(nome);
	}

	set<string>::iterator pt = lista.begin();

	while(k > 1){
		pt++;
		k--;
	}

	cout << *pt << endl;

	return 0;
}
