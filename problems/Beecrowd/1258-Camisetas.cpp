#include <bits/stdc++.h>

using namespace std;

struct elem{
	string nome, cor, tamanho;
};

int mtd(elem a, elem b){
	if(a.cor != b.cor) return a.cor < b.cor;
	else if(a.tamanho != b.tamanho) return a.tamanho > b.tamanho;
	return a.nome <= b.nome;
}

int main(){
	int n, cont = 0;
	while(cin >> n){
		if(n == 0) break;
		if(cont != 0) cout << endl;
		vector <elem> nomes;
		for(int i = 0; i < n; i++){
			elem aux;
			getchar();

			string nome; getline(cin, nome);
			aux.nome = nome;

			cin >> aux.cor >> aux.tamanho;
			nomes.push_back(aux);
		}
		sort(nomes.begin(), nomes.end(), mtd);
		for(int i = 0; i < nomes.size(); i++) cout << nomes[i].cor << " " << nomes[i].tamanho << " " << nomes[i].nome << endl;
		cont++;
	}
	return 0;
}
