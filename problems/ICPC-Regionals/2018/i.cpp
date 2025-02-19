#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector <int> lamp(m+1, 0);

    int l; cin >> l;
    while(l--){
        int aux; cin >> aux;
        lamp[aux]++;
    }

    vector <vector<int>> interr(n+1, vector<int>());

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        interr[i%n].resize(x);
        for(int j = 0; j < x; j++) cin >> interr[i%n][j];
    }

    for(int i = 1; i <= 2*n; i++){
        for(int j = 0; j < interr[i%n].size(); j++){
            lamp[interr[i%n][j]]++;
            lamp[interr[i%n][j]] %= 2;
        }

        bool solved = true;
        for(int j = 0; j < lamp.size(); j++){
            if(lamp[j]) solved = false;
        }

        if(solved){
            cout << i << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;

    return 0;
}