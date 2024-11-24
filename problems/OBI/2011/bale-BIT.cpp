#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int bailarina[MAXN], BIT[MAXN], n;

void updt(int ind, int value){
    while(ind <= n){
        BIT[ind] += value;
        ind += ind & (-ind);
    }
}

int query(int ind){
    int aux = 0;
    while(ind > 0){
        aux += BIT[ind];
        ind -= ind & (-ind);
    }
    return aux;
}

int main(){
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> bailarina[i];

    int ans = 0;

    for(int i = n; i > 0; i--){
        ans += query(bailarina[i]);
        updt(bailarina[i], 1);
    }

    cout << ans << endl;

    return 0;
}