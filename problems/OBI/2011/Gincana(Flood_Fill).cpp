#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

int grupo[MAXN];
vector <int> amizades[MAXN];

void DFS(int x){
    for(int i = 0; i < amizades[x].size(); i++){
        int atual = amizades[x][i];
        if(grupo[atual] == 0){
            grupo[atual] = grupo[x];
            DFS(atual);
        }
    }
}

int main(){
    int alunos, linhas;

    cin >> alunos >> linhas;

    for(int i = 1; i <= linhas; i++){
        int amigo1, amigo2;

        cin >> amigo1 >> amigo2;

        amizades[amigo1].push_back(amigo2);
        amizades[amigo2].push_back(amigo1);
    }

    int cont = 0;

    for(int i = 1; i <= alunos; i++){
        if(grupo[i] == 0){
            cont++;
            grupo[i] = cont;
            DFS(i);
        }
    }

    cout << cont << endl;

    return 0;

}