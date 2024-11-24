#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    set <int> targets;

    for(int i = 0; i < n; i++){
        int curr; cin >> curr;

        if(targets.find(curr) != targets.end()) targets.erase(curr);

        targets.insert(curr+1);
    }

    cout << (int)targets.size() << endl;

    return 0;
}