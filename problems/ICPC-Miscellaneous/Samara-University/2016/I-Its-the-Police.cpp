#include <bits/stdc++.h>
#define MAXN 200007
#define lli long long int

using namespace std;

vector<int> adj[MAXN];
int grade[MAXN];

int main(){
    int n, m; cin >> n >> m;

    vector <int> grade(n+1, 0), mark(n+1, 1);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        grade[u]++;
        grade[v]++;
    }

    lli max_grade = MAXN;
    int vtx;

    for(int i = 1; i <= n; i++){
        if(grade[i] < max_grade){
            max_grade = grade[i];
            vtx = i;
        }
    }

    mark[vtx] = 0;
    for(int i = 0; i < adj[vtx].size(); i++) mark[adj[vtx][i]] = 0;

    for(int i = 1; i <= n; i++) cout << mark[i] << " ";

    cout << endl;

    return 0;
}