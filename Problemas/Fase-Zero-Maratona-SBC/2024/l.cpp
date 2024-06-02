#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  vector<string> ordemQuartos;
  vector<string> ordemIdade;
  set<string> criancas;

  cin >> n;
  
  for(int i = 0; i < n; i++) {
    string aux;
    cin >> aux;

    ordemQuartos.push_back(aux);
  }

  for(int i = 0; i < n; i++) {
    string aux;
    cin >> aux;

    ordemIdade.push_back(aux);
    criancas.insert(aux);
  }

    int iterador = 0;

    for(int i = 0; i < n; i++){
        while(criancas.find(ordemIdade[iterador]) == criancas.end()){
            iterador++;
        } 
        cout << ordemIdade[iterador];

        if(i != n-1) cout << " ";

        criancas.erase(ordemQuartos[i]);
    }

    cout << endl;

  return 0;
}