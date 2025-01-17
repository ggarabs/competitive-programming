#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, k; cin >> n >> m >> k;

    string password; cin >> password;

    vector <string> poss(m);

    for(int i = 0; i < m; i++){
        cin >> poss[i];
        sort(poss[i].begin(), poss[i].end());
    }

    int p; cin >> p;
    p--;

    vector<int> rep;

    while(p > 0){
        rep.push_back(p%k);
        p /= k;
    }
    rep.resize(m, 0);
    reverse(rep.begin(), rep.end());

    for(int i = 0, j = 0; i < password.size(); i++){
        if(password[i] == '#') cout << poss[j][rep[j++]];
        else cout << password[i];
    }
    cout << endl;

    return 0;
}