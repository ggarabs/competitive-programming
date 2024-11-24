#include <bits/stdc++.h>

using namespace std;

int main(){
    set <int> x, y;
    for(int i = 0; i < 4; i++){
        int x3, y3; cin >> x3 >> y3;
        if(x.find(x3) == x.end()) x.insert(x3);
        if(y.find(y3) == y.end()) y.insert(y3);
    }

    int resp = abs((*(x.begin())-*(++x.begin()))*(*(y.begin())-*(++y.begin())));

    cout << resp << endl;

}