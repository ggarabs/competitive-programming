#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        int n, m, q; cin >> n >> m >> q;

        vector <pair<int, int>> pos;

        pos.push_back({m, m});

        for(int i = 0; i < q; i++){
            int v; cin >> v;

            int size =  pos.size();

            for(int j = 0; j < size; j++){
                if(v < pos[j].first) pos[j].first = max(pos[j].first-1, 0);
                else if(v > pos[j].second) pos[j].second = min(pos[j].second+1, n);
                else{
                    if(i == 0) pos.clear();
                    pos.push_back({1, 1});
                    pos.push_back({n, n});
                }
            }

            sort(pos.begin(), pos.end());

            int k = 0;

            vector <pair <int, int>> aux;

            for(int j = 1; j < pos.size(); j++){
                if(pos[j].first <= pos[k].second) pos[k].second = pos[j].second;
                else{
                    aux.push_back({pos[k].first, pos[k].second});
                    k = j;
                }
            }

            aux.push_back({pos[k].first, pos[k].second});

            pos.clear();

            int ans = 0;

            for(int j = 0; j < aux.size(); j++){
                pos.push_back({aux[j].first, aux[j].second});
                ans += aux[j].second-aux[j].first+1;
            }

            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}