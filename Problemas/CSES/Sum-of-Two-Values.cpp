#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, x; cin >> n >> x;

    vector <int> values(n, 0);
    for(int i = 0; i < n; i++) cin >> values[i];

    map <int, int> elem;
    for(int i = 0; i < n; i++){
        if(elem.find(x-values[i]) != elem.end()){
            cout << i+1 << " " << elem[x-values[i]] << endl;
            return 0;
        }
        elem[values[i]] = i+1;
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}