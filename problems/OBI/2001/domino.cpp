#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXN 107
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool vis[MAXN];
vector <int> graph[MAXN];

void DFS(int orig){
    vis[orig] = true;
    for(int i = 0; i < graph[orig].size(); i++){
        if(!vis[graph[orig][i]]){
            DFS(graph[orig][i]);
        }
    }
}

int main(){ _
    int n, it = 1;

    while(cin >> n && n){
        vector <pair<int, int>> peca;
        int grau[MAXN];
        bool resp = true;

        memset(grau, 0, sizeof(grau));
        memset(vis, 0, sizeof(vis));

        for(int i = 0; i < n; i++) graph[i].clear();

        for(int i = 0; i < n; i++){
            int x, y; cin >> x >> y;
            peca.pb({x, y});
        }

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){ // mudar isso aqui
                if(peca[i].first == peca[j].first){
                    graph[i].pb(j); graph[j].pb(i);
                    grau[i]++; grau[j]++;
                }
                if(peca[i].first == peca[j].second){
                    graph[i].pb(j); graph[j].pb(i);
                    grau[i]++; grau[j]++;
                }
                if(peca[i].second == peca[j].first){
                    graph[i].pb(j); graph[j].pb(i);
                    grau[i]++; grau[j]++;
                }
                if(peca[i].second == peca[j].second){
                    graph[i].pb(j); graph[j].pb(i);
                    grau[i]++; grau[j]++;
                }
            }
        }

        DFS(0);

        int count[2] = {0, 0};

        for(int i = 0; i < n; i++){
            if(!vis[i]) resp = false;
            count[grau[i]%2]++;
        }

        if(count[1] > 2) resp = false;

        cout << "Teste " << it++ << endl;
        cout << (resp ? "sim" : "nao") << endl;

        cout << endl;
    }


    exit(0);
}