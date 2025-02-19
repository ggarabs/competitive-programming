#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k; cin >> n >> k;

    vector <int> seq;
    vector <pair<int, int>> blocks;

    for(int i = 0; i < n; i++){
        int ni, ci; cin >> ni >> ci;
        blocks.push_back({ni, ci});
        seq.push_back(ci);
    }

    sort(blocks.begin(), blocks.end());

    for(int i = 0; i < blocks.size(); i++){
        if(seq[i] != blocks[i].second){
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "Y" << endl;

    return 0;
}