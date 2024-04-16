#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

int mark[MAXN];

int main(){
    int q, e; cin >> q >> e;
    for(int i = 0; i < e; i++){
        int aux; cin >> aux;
        mark[aux] = 1;
    }
    for(int i = 0; i < q; i++){
        int aux; cin >> aux;
        cout << 1 - mark[aux] << endl;
        if(mark[aux] == 0) mark[aux] = 1;
    }
    return 0;
}