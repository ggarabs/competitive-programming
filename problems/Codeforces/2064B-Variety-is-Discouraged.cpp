#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector <pair<int, int>> ocurr(n+1, {-1, -1});

        for(int i = 1; i <= n; i++){
            int num; cin >> num;
            if(ocurr[num].first == -1) ocurr[num] = {i, i};
            else ocurr[num].second = i;
        }

        vector <int> idx;
        
        for(int i = 1; i <= n; i++){
            if(ocurr[i].first != -1 && ocurr[i].first == ocurr[i].second) idx.push_back(ocurr[i].first);
        }

        if(idx.empty()){
            cout << "0" << endl;
            continue;
        }

        sort(idx.begin(), idx.end());

        pair<int, int> ans = {idx[0], idx[0]}, aux = {idx[0], idx[0]};
        for(int i = 1; i < idx.size(); i++){
            if(idx[i] == aux.second + 1) aux.second = idx[i];
            else{
                if((aux.second - aux.first) > (ans.second - ans.first)) ans = aux;
                aux = {idx[i], idx[i]};
            }
        }

        if((aux.second - aux.first) > (ans.second - ans.first)) ans = aux;

        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}