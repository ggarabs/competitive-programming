#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

using namespace std;

bool check(vector<int> v1, vector<int> t){
    bool sol = true;
    for(int i = 0; i < v1.size(); i++) if(v1[i] != t[i]) sol = false;
    if(sol) return true;
    sol = true;
    for(int i = v1.size()-1; i >= 0; i--) if(v1[i] != t[v1.size()-1-i]) sol = false;
    return sol;
}

bool solve(vector<int> v1, vector<int>t){
    if(v1.size() < t.size()) return false;
    if(v1.size() == t.size()) return check(v1, t);
    for(int meio = 1; meio < v1.size(); meio++){
        vector<int> aux;
        if(meio <= v1.size()/2){
            int i = meio-1, j = meio;
            while(i >= 0 && j < v1.size()){
                aux.push_back(v1[i] + v1[j]);
                i--; j++;
            }
            for(;j < v1.size(); j++) aux.push_back(v1[j]);
        }else{
            for(int i = 0; i < 2*meio-v1.size(); i++) aux.push_back(v1[i]);
            int i = 2*meio-v1.size(), j = v1.size()-1;
            while(i < meio && j >= meio){
                aux.push_back(v1[i] + v1[j]);
                i++; j--;
            }
        }
        if(solve(aux, t)) return true;
    }
    return false;
}

int main(){ _
    int n; 
    while(cin >> n){
        vector <int> fita(n, 0);
        for(int i = 0; i < n; i++) cin >> fita[i];

        int m; cin >> m;

        vector <int> target(m, 0);
        for(int i = 0; i < m; i++) cin >> target[i];

        cout << (solve(fita, target) ? 'S' : 'N') << endl;
    }

    return 0;
}