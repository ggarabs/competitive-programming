#include <bits/stdc++.h>
#define pb push_back
#define lli long long int
#define mod %

const int MAXN = 3*1e5+7, INF = 998244353;

using namespace std;

int sum[MAXN], parent[MAXN];
lli levels_sum[MAXN];
vector <int> tree[MAXN], level[MAXN];

void DFS(int x, int lvl){
   level[lvl].pb(x);
   for(int &child : tree[x]) DFS(child, lvl+1);
}

lli solve(int n){
    for(int i = n; i >= 1; i--){
        if(level[i].empty()) continue;
        for(int &node : level[i]){
            int ans = levels_sum[i+1] mod INF;
            ans = ((ans - sum[node] mod INF) + INF) mod INF;
            ans = (ans + 1) mod INF;

            levels_sum[i] = (levels_sum[i] +  ans mod INF) mod INF;

            sum[parent[node]] = (sum[parent[node]] mod INF + ans mod INF) mod INF;
        }
    }
    return (levels_sum[1]+1) mod INF;
}


int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
    
        for(int i = 2; i <= n; i++){
            int p; cin >> p;
            tree[p].pb(i);
            parent[i] = p;
        }
        
        DFS(1, 0);

        cout << solve(n) << endl;

        memset(sum, 0, sizeof(sum));
        memset(levels_sum, 0, sizeof(levels_sum));
        memset(parent, 0, sizeof(parent));

        for(int i = 0; i <= n; i++){
            tree[i].clear();
            level[i].clear();
        }

    }
    return 0;
}