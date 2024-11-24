#include <bits/stdc++.h>

using namespace std;

int main(){
	int cont = 0;
	string atual = "";
	char tecla = '2';
	map <char, string> dic;
	dic[' '] = "0";
	for(char letter = 'a', cont = 0; letter <= 'z'; letter++){
		atual += tecla;
		dic[letter] = atual;
		dic[letter - 32] = '#' + dic[letter];
		if(letter == 'r' || letter == 'y') continue;
		cont++;
		if(cont % 3 == 0 && cont != 0){
			tecla++;
			atual = "";
		}
	}

	int n;
	cin >> n;
	getchar();
	char last = '%';

	for(int i = 0; i < n; i++){
		string nome;
		getline(cin, nome);
		for(int j = 0; j < nome.size(); j++){
			if(dic[nome[j]][0] == last) cout << '*';
			cout << dic[nome[j]];
			last = dic[nome[j]][dic[nome[j]].size()-1];
		}
		last = '%';
		cout << endl;
	}

	return 0;
}
