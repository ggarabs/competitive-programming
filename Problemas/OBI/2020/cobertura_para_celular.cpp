#include <bits/stdc++.h>
#define MAXN 10007

using namespace std;

vector <int> graph[MAXN];
int componente[MAXN];

struct Ponto{
    int x, y;
};

float dist(Ponto a, Ponto b){
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

void DFS(int x){
    for(int i = 0; i < graph[x].size(); i++){
        int viz = graph[x][i];
        if(componente[viz] == 0){
            componente[viz] = componente[x];
            DFS(viz);
        }
    }
}

int main(){
    int n;
    cin >> n;

    Ponto lista[MAXN];

    for(int i = 0; i < n; i++) cin >> lista[i].x >> lista[i].y;

    int alcance;
    cin >> alcance;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist(lista[i], lista[j]) <= alcance){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    int cont = 0;

    for(int i = 0; i < n; i++){
        if(componente[i] == 0){
            componente[i] = ++cont;
            DFS(i);
        }
    }

    cout << ((cont > 1) ? "N" : "S") << endl;

    return 0;
}