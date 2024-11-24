#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

vector <int> adj_list[MAXN];
vector <pair <int, int>> arvore;
int comp[MAXN];

void DFS(int vtx){
  for(int i = 0; i < adj_list[vtx].size(); i++){
    int viz = adj_list[vtx][i];
    if(comp[viz] == 0){
      comp[viz] = comp[vtx];
      DFS(viz);
    }
  }
}

double dist(int i, int j){
  long long int d1 = pow(arvore[i].first - arvore[j].first, 2);
  long long int d2 = pow(arvore[i].second - arvore[j].second, 2);
  double d = sqrt(d1 + d2);
  return d;
}

int main(){
  int arvores, alcance;
  cin >> arvores >> alcance;

  for(int i = 1; i <= arvores; i++){
    int x, v;
    cin >> x >> v;
    arvore.push_back({x, v});
  }

  for(int i = 0; i < arvores-1; i++){
    for(int j = i+1; j < arvores; j++){
      if(dist(i, j) <= alcance){
        adj_list[i].push_back(j);
        adj_list[j].push_back(i);
      }
    }
  }

  comp[0] = 1;
  DFS(0);
  
  for(int i = 1; i < arvore.size(); i++){
    if(comp[i] == 0){
      cout << "N" << endl;
      return 0;
    }
  }

  cout << "S" << endl;
  return 0;
  
}
