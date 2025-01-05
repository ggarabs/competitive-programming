#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector <int> list(n, 0), aux(n, 0);
        for(int i = 0; i < n; i++){
            cin >> list[i];
            aux[i] = list[i];
        }

        sort(aux.begin(), aux.end());
        map <int, int> mp;

        for(int i = 0, cont = 0; i < aux.size(); i++){
            if(mp.find(aux[i]) == mp.end()){
                mp[aux[i]] = cont++;
            }
        }

        vector<int> qtd(mp.size()+1, 0);

        for(int i = 0; i < list.size(); i++) qtd[mp[list[i]]]++;

        sort(qtd.begin(), qtd.end());

        int cont = 0;
        for(int i = 0; i < qtd.size(); i++){
            if(k >= qtd[i]){ k -= qtd[i]; cont++; }
            else break;
        }

        if(qtd.size()-cont == 0) cont--;

        cout << qtd.size()-cont << endl;

    }
    return 0;
}