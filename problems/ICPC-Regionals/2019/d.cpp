#include <bits/stdc++.h>
#define lli long long int

const int MAXN = 1e5+7;

using namespace std;

vector <int> tree[MAXN], h(MAXN, 0), path_roots;

int calc_height(int x){
    int dist = 1;
    for(int i = 0; i < tree[x].size(); i++){
        int child = tree[x][i];

        dist = max(dist, 1 + calc_height(child));
    }
    return h[x] = dist;
}

void solve(int x){
    bool in_path = false;
    for(int i = 0; i < tree[x].size(); i++){
        int child = tree[x][i];

        if(!in_path && h[x] == h[child]+1) in_path = true;
        else path_roots.push_back(h[child]);

        solve(child);
    }
}

int main(){
    int n, k; cin >> n >> k;

    for(int i = 2; i <= n; i++){
        int parent; cin >> parent;

        tree[parent].push_back(i);
    }

    calc_height(1);

    path_roots.push_back(h[1]);

    solve(1);

    sort(path_roots.begin(), path_roots.end());
    reverse(path_roots.begin(), path_roots.end());

    int ans = 0;

    for(int i = 0; i < k; i++) ans += path_roots[i];

    cout << ans << endl;

    return 0;
}