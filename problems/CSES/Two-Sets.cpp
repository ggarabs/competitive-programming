#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    long long int total = n*(n+1)/2;
    if(total % 2 != 0){
        cout << "NO" << endl;
        return 0;
    }

    vector <int> sets[2];
    long long int last = (n % 2 == 1) ? n : n+1;

    for(int i = 1; i <= n/2; i++){
        sets[i%2].push_back(i);
        sets[i%2].push_back(last-i);
    }

    if(n % 2 == 1) sets[0].push_back(n);

    cout << "YES" << endl;
    for(int i = 0; i < 2; i++){
        cout << (int)sets[i].size() << endl;
        for(int j = 0; j < sets[i].size(); j++){
            cout << sets[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}