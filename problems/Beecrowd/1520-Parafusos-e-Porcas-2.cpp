#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> rack;
        for(int i = 0; i < n; i++){
            int x, y; cin >> x >> y;

            while(x <= y){
                rack.push_back(x);
                x++;
            }
        }

        sort(rack.begin(), rack.end());

        int q; cin >> q;
        bool found = 0;

        vector <int> f;

        for(int i = 0; i < rack.size(); i++) if(rack[i] == q) f.push_back(i);

        if(!f.size()) cout << q << " not found" << endl;
        else cout << q << " found from " << f[0] << " to " << f[f.size()-1] << endl;

    }
    return 0;
}