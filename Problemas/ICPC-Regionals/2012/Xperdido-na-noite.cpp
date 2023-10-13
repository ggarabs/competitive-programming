#include <bits/stdc++.h>
#define MAXN 107

using namespace std;

vector <int> graph[MAXN];
double prob[MAXN];
bool vis[MAXN];

void BFS(int x){
    queue <int> fila;
    fila.push(x);
    prob[x] = 1.0;

    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();
        vis[atual] = true;
        vector <int> aux;

        int cont = 0;

        for(int i = 0; i < graph[atual].size(); i++){
            int viz = graph[atual][i];
            if(!vis[viz]){
                cont++;
                aux.push_back(viz);
            }
        }

        for(int i = 0; i < aux.size(); i++){
            prob[aux[i]] = prob[atual]/cont;
            fila.push(aux[i]);
        }
    }
}

int main(){
    int n, a, b, c;
    while(cin >> n >> a >> b >> c){
        memset(vis, 0, sizeof(vis));
        memset(prob, 0, sizeof(prob));

        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        BFS(a);

        cout.precision(6);
        cout.setf(ios::fixed);

        cout << prob[b] << endl;

        for(int i = 1; i <= n; i++) graph[i].clear();
    }

    return 0;
}