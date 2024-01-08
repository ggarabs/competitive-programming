#include <bits/stdc++.h>
#define MAXN 200007
#define pb push_back

using namespace std;

vector <int> tree[MAXN];
int dp[MAXN];

int solve(int raiz){
    if(dp[raiz] != -1) return dp[raiz];
    int aux = 0;
    for(int i = 0; i < tree[raiz].size(); i++) aux += solve(tree[raiz][i]);
    return dp[raiz] = (int)tree[raiz].size() + aux;
}

int main(){
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    for(int u = 2; u <= n; u++){
        int v;
        cin >> v;

        tree[v].pb(u);
    }

    for(int i = 1; i <= n; i++) cout << solve(i) << " ";
    cout << endl;

    return 0;
}