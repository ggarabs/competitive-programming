#include <bits/stdc++.h>

using namespace std;

struct aluno{
	string nome, regiao;
	int dist;
};

int mtd(aluno a, aluno b){
	if(a.dist != b.dist) return a.dist < b.dist;
	else if(a.regiao != b.regiao) return a.regiao < b.regiao;
	return a.nome <= b.nome;
}

int main(){
	int q;
	while(cin >> q){
		vector <aluno> alunos;
		for(int i = 0; i < q; i++){
			aluno aux;
			cin >> aux.nome >> aux.regiao >> aux.dist;
			alunos.push_back(aux);
		}
		sort(alunos.begin(), alunos.end(), mtd);
		for(int i = 0; i < q; i++){
			cout << alunos[i].nome << endl;
		}
	}
	return 0;
}
