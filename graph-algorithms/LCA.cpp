#include <bits/stdc++.h> 
#define MAXN 100007
#define MAXL 18

using namespace std;

vector <pair<int, int>> tree[MAXN];
long long int dist[MAXN];
int prof[MAXN], anc[MAXN][MAXL];

void DFS(int orig){
  for(int i = 0; i < tree[orig].size(); i++){
    int viz = tree[orig][i].second;
    int wgt = tree[orig][i].first;
    if(dist[viz] == -1){
      dist[viz] = dist[orig]+wgt;
      prof[viz] = prof[orig]+1;
      DFS(viz);
    }
  }
}

void calc_anc(int n){
  for(int i = 1; i <= MAXL; i++){
    for(int j = 1; j < n; j++){
      if(prof[j] - (1 << i) >= 0) anc[j][i] = anc[anc[j][i-1]][i-1];
    }
  }
}

int lca(int x, int y){
  if(prof[x] < prof[y]) swap(x, y);

  for(int i = MAXL; i >= 0; i--){
    if(prof[x] - (1 << i) >= prof[y]) x = anc[x][i];
  }

  if(x == y) return x;

  for(int i = MAXL-1; i >= 0; i--){
    if(anc[x][i] != -1 && anc[x][i] != anc[y][i]){
        x = anc[x][i];
        y = anc[y][i];
    }
  }

  return anc[x][0];

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;

  while(cin >> n){
    if(n == 0) return 0;
    
    memset(dist, -1, sizeof(dist));
    memset(prof, -1, sizeof(prof));
    memset(anc, -1, sizeof(anc));
  
    for(int i = 1; i <= n-1; i++){
      int ai, li;
      cin >> ai >> li;
  
      tree[ai].push_back({li, i});
      anc[i][0] = ai;
    }
  
    dist[0] = 0; prof[0] = 0;
    DFS(0);

    calc_anc(n);
  
    int q;
    cin >> q;
  
    for(int i = 0; i < q; i++){
      int s, t;
      cin >> s >> t;
  
      cout << dist[s]+dist[t]-2*dist[lca(s,t)];

      if(i != q-1) cout << " ";  
    }
  
    cout << endl;
  
    for(int i = 0; i < n; i++) tree[i].clear();
  }

  return 0;
}