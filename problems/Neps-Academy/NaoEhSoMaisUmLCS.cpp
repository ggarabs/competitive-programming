#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, aux = 0;
    cin >> n >> m;

    unordered_map <int, int> rel;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        rel[x]=++aux;
    }

    vector <int> v, pilha;

    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        if(rel[x]) v.push_back(rel[x]);
    }

    for(int i = 0; i < v.size(); i++){
        vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);

        if(it == pilha.end()) pilha.push_back(v[i]);
        else *it = v[i];
    }

    cout << (int)pilha.size() << endl;

    return 0;
}