#include <bits/stdc++.h>
#define MAXN 100107

using namespace std;

int desl_x[30] = {0, 1, 0, -1, 0, 2, 0, -2, 0, 1, 1, -1, -1, 3, 0, -3, 0, 2, -2, 2, -2, 1, 1, -1, -1, 2, 2, -2, -2};
int desl_y[30] = {0, 0, 1, 0, -1, 0, 2, 0, -2, 1, -1, 1, -1, 0, 3, 0, -3, 2, 2, -2, -2, 2, -2, 2, -2, 1, -1, 1, -1};
int parent[MAXN], w[MAXN];

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void join(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(w[x] < w[y]){
        parent[x] = y;
    }else if(w[x] > w[y]){
        parent[y] = x;
    }else{
        parent[x] = y;
        w[y]++;
    }
}

int main(){
    int n, q, d; cin >> n >> q >> d;
    vector<pair<int, int>> coord;
    map<pair<int, int>, int> hash;
    int cor[4] = {0, 4, 12, 28};

    for(int i = 0; i < n; i++) parent[i] = i;

    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        coord.push_back({x, y});
        hash.insert({{x, y}, i});
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= cor[d]; j++){
            int new_x = coord[i].first + desl_x[j], new_y = coord[i].second + desl_y[j];
            if(hash.find({new_x, new_y}) != hash.end()){
                if(find(i) != find(hash[{new_x, new_y}])) join(i, hash[{new_x, new_y}]);
            }
        }
    }

    for(int i = 0; i < q; i++){
        int s1, s2; cin >> s1 >> s2;s1--;s2--;
        if(find(s1) == find(s2)) cout << 'S' << endl;
        else cout << 'N' << endl;
    }

    return 0;    
}