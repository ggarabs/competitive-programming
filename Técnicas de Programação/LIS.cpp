#include <bits/stdc++.h>
#define pb push_back
#define MAXN 100007

using namespace std;

vector <int> lis(vector <int> &v){ // O(n*logn)
    vector <int> pilha, resp;
    int pos[MAXN], pai[MAXN];

    for(int i = 0; i < v.size(); i++){
        vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]); //binary_search
        // lower = menor elemento maior ou igual ao v[i]
        // upper = menor elemento maior que v[i]

        int p = it-pilha.begin(); // posição que guardarei o elemento

        if(it == pilha.end()) pilha.pb(v[i]);
        else *it = v[i];

        pos[p] = i;

        if(p==0) pai[i] = -1;
        else pai[i] = pos[p-1];
    }

    int p = pos[pilha.size()-1];

    while(p != -1){
        resp.pb(v[p]);
        p = pai[p];
    }

    reverse(resp.begin(), resp.end());

    return resp;
}