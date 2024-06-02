#include <bits/stdc++.h>
#define MAXN 200007

using namespace std;

int n, m, k;

vector<pair<int, int>> graph[MAXN];
bool vis[MAXN];
long long int qtd[MAXN];

void BFS(int x) {
  priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> fila;
  fila.push({0, x});
  int qtdv = 1;
  while (!fila.empty()) {
    pair<long long int, long long int> topo = fila.top();
    fila.pop();
    if(vis[topo.second]) continue;
    qtd[qtdv++] = topo.first;
    if(qtdv == n+1) break;
    vis[topo.second] = 1;
    for (int i = 0; i < graph[topo.second].size(); i++) {
      pair<long long int, long long int> v = graph[topo.second][i];
      if (vis[v.second] == 0) {
        fila.push(v);
      }
    }
  }
}

  int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      graph[u].push_back({c, v});
      graph[v].push_back({c, u});
    }

    BFS(1);

    cout << qtd[k] << endl;

    return 0;
  }