#include <bits/stdc++.h>
#define MAXN 100007
#define pb push_back

using namespace std;

vector <int> tree[MAXN];
bool vis[MAXN];
double prob[MAXN];
int d[MAXN];

void solve(int vtx, int dist){
    vis[vtx] = 1;
    for(int i = 0; i < tree[vtx].size(); i++){
        if(!vis[tree[vtx][i]]){
            
            int desc = tree[vtx].size();
            if(vtx != 1) desc -= 1;

            prob[tree[vtx][i]] *= (1.0/desc)*prob[vtx];
            d[tree[vtx][i]] = dist+1;
            solve(tree[vtx][i], dist+1);
        }
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) prob[i] = 1.0;

    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;

        tree[u].pb(v);
        tree[v].pb(u);
    }

    solve(1, 0);

    double ans = 0;

    for(int i = 2; i <= n; i++){
        if(tree[i].size() == 1){
            ans += prob[i]*d[i];
        }
    }

    cout.precision(15);
    cout.setf(ios::fixed);

    cout << ans << endl;

    return 0;
}