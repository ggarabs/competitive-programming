#include <bits/stdc++.h>
#define MAXN 1070

using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector <int> state(m+1, 0);
    int l; cin >> l;
    for(int i = 0; i < l; i++){
        int aux; cin >> aux;
        state[aux] = 1;
    }

    vector <int> interr[MAXN];
    for(int i = 0; i < n; i++){
        int aux; cin >> aux;
        for(int j = 0; j < aux; j++){
            int lamp; cin >> lamp;
            interr[i].push_back(lamp);
        }
    }

    for(int i = 1; i <= 2*n; i++){
        for(int j = 0; j < interr[(i-1)%n].size(); j++) state[interr[(i-1)%n][j]] ^= 1;
        
        bool apagouTudo = true;
        for(int j = 0; j < state.size(); j++) if(state[j] == 1) apagouTudo = false;

        if(!apagouTudo) continue;

        cout << i << endl;
        return 0;
    }

    cout << -1 << endl;

    return 0;
}