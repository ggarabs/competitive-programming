#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, l, o, d; cin >> t >> l >> o >> d;

    vector <vector <int>> linha(l+1);
    vector <set <int>> mapa(t+1);

    for(int i = 1; i <= l; i++){
        int c; cin >> c;
        for(int j = 0; j < c; j++){
            int aux; cin >> aux;
            linha[i].push_back(aux);
            mapa[aux].insert(i);
        }
    }

    vector <int> dist(t+1, l+10);
    vector <bool> vis(t+1, false);

    int curr = o;
    dist[curr] = 0;
    queue <int> q;
    q.push(curr);

    while(!q.empty()){
        int f = q.front();
        q.pop();
        vis[f] = true;

        for(auto &it : mapa[f]){
            int ln = it;
            for(int k = 0; k < linha[ln].size(); k++){
                int ngbr = linha[ln][k];
                if(vis[ngbr]) continue;
                if(dist[ngbr] > dist[f] + 1){
                    dist[ngbr] = dist[f] + 1;
                    q.push(ngbr);
                }
            }
        }
    }

    cout << dist[d] << endl;

    return 0;
}