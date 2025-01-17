#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector <vector<char>> m(n+1, vector<char>(n+1));
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> m[i][j];

        vector<int> p;
        p.push_back(1);

        for(int i = 2; i <= n; i++){
            int size = p.size(), pos = 0;
            for(int j = 0; j < size; j++){
                if(m[i][p[j]] == '0') break;
                else pos++;
            }
            p.insert(p.begin()+pos, i);
        }

        for(int i = 0; i < p.size(); i++) cout << p[i] << " ";
        cout << endl;
    }
    return 0;
}