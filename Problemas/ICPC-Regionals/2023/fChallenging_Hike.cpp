#include <bits/stdc++.h>
#define MAXN 100007
#define pb push_back

// Maior subsequencia crescente em árvore

using namespace std;

vector <int> tree[MAXN];
int dp[MAXN], values[MAXN];
bool vis[MAXN];

int solve(int x, int last){
    if(dp[x] != -1) return dp[x];
    int take=0, not_take=0;
    vis[x] = true;
    for(int i = 0; i < tree[x].size(); i++){
        if(vis[tree[x][i]]) continue;
        not_take = max(not_take, solve(tree[x][i], last));
        if(values[x] > last) take = max(take, 1+solve(tree[x][i], values[x]));
    }
    return dp[x] = max(take, not_take);
}

int main(){
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    for(int i = 2; i <= n; i++){
        int s;
        cin >> s;
        tree[i].pb(s);
        tree[s].pb(i);
    }

    for(int i = 1; i <= n; i++) cin >> values[i];

    solve(1, 0);

    for(int i = 2; i <= n; i++) cout << dp[i] << " ";

    cout << endl;

    return 0;
}