#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    vector<int> cubes;

    for(int i = 0; i < n; i++){
        int value; cin >> value;

        auto st = upper_bound(cubes.begin(), cubes.end(), value);

        if(st == cubes.end()) cubes.push_back(value);
        else *st = value;
    }

    cout << cubes.size() << endl;

    return 0;
}