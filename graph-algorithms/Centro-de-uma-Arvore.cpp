#include <bits/stdc++.h>
#define MAXN 100007
#define INF 1000000007

using namespace std;

int n, parent[MAXN], dist[2][MAXN];
vector <int> tree[MAXN];

// u é o vértice atual
// p é o pai do vértice atual
// d é a distância para o nó inicial
// q é a vez da DFS pra achar o centro: primeira ou segunda vez
void DFS(int u, int p, int d, int q){
    dist[q][u] = d;
    parent[u] = p;

    for(int i = 0; i < tree[u].size(); i++){
        int viz = tree[u][i];
        if(viz != p){ // serve para não retornar ao mesmo vértice
            DFS(viz, u, d+1, q);
        }
    }
}

// O centro de uma árvore pertence a qualquer diâmetro dela, por isso a subimos de pai em pai.

int find_center(int u, int v){ // u e v são extremos de um diâmetro da árvore
    DFS(u, -1, 0, 0);
    DFS(v, -1, 0, 1);

    int cur = u, exc = INF, center = u;

    while(cur != -1){
        if(max(dist[0][cur], dist[1][cur]) < exc){
            exc = max(dist[0][cur], dist[1][cur]);
            center = u;
            cur = parent[u];
        }
    }

    return center;
}
