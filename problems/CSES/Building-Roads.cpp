#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int parent[MAXN], weight[MAXN];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void join(int a, int b){
    a = find(a); b = find(b);

    if(weight[a] < weight[b]) parent[a] = b;
    else if(weight[b] < weight[a]) parent[b] = a;
    else{
        parent[a] = b;
        weight[b]++;
    }
}

int main(){
    int n, m; cin >> n >> m;

    for(int i = 1; i <= n; i++) parent[i] = i;

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if(find(a) != find(b)) join(a, b);
    }

    set <int> components;

    for(int i = 1; i <= n; i++) components.insert(find(i));

    cout << components.size()-1 << endl;
    while(components.size() > 1){
        auto ptr = components.begin();
        cout << *ptr << " " << *(++ptr) << endl;
        components.erase(components.begin());
    }

    return 0;
}