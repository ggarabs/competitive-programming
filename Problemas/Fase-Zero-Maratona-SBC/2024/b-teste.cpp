#include <bits/stdc++.h>
#define MAXN 200007

using namespace std;

int n, m, k;

vector<pair<int, int>> graph[MAXN];
int vis[MAXN];
long long int dist[MAXN];

void BFS(int x) {
  priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> fila;
  fila.push({0, x});
  dist[x] = 0;

  while (!fila.empty()) {
    pair<long long int, int> topo = fila.top();
    fila.pop();

    int node = topo.second;
    if(vis[node]) continue;

    vis[node] = 1;

    for (auto &edge : graph[node]) {
      int neighbor = edge.second;
      long long int weight = edge.first;

      if (!vis[neighbor] && dist[node] + weight < dist[neighbor]) {
        dist[neighbor] = dist[node] + weight;
        fila.push({dist[neighbor], neighbor});
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

  fill(dist, dist + MAXN, LLONG_MAX);
  fill(vis, vis + MAXN, 0);

  BFS(1);

  if (dist[k] == LLONG_MAX) {
    cout << -1 << endl;
  } else {
    cout << dist[k] << endl;
  }

  return 0;
}