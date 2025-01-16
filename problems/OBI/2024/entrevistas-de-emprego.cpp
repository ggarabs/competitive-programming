#include <bits/stdc++.h>
#define MAXN 2507

using namespace std;

int parent[MAXN], h[MAXN];

int find(int x){
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(h[x] == h[y]){
        parent[y] = x;
        h[x]++;
    }else if(h[x] > h[y]) parent[y] = x;
    else parent[x] = y;
}

int main(){
    int n; cin >> n;

    for(int i = 1; i <= n; i++){ parent[i] = i; h[i] = 1; }

    for(int i = 1; i <= n; i++){
        string ft; cin >> ft;
        for(int j = 1; j <= ft.size(); j++) if(ft[j-1] == '1') join(i,j);
    }

    int e; cin >> e;

    while(e--){
        int q; cin >> q;

        vector <int> cand(q, 0);
        vector <bool> group(n+1, false);
        bool has_friend = false;

        for(int i = 0; i < q; i++) cin >> cand[i];

        for(int i = 0; i < q; i++){
            int aux = find(cand[i]);
            if(group[aux]){
                has_friend = true;
                break;
            }
            group[aux] = 1;
        }

        cout << (has_friend ? 'S' : 'N') << endl;
    }

    return 0;
}