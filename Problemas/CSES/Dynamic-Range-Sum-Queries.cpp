#include <bits/stdc++.h>
#define MAXN 200007

using namespace std;

int n;
long long int BIT[MAXN];

void update(int ind, int value){
    while(ind <= n){
        BIT[ind] += value;
        ind += ind&(-ind);
    }
}

long long int sum(int ind){
    long long int aux = 0;
    while(ind > 0){
        aux += BIT[ind];
        ind -= ind&(-ind);
    }
    return aux;
}

int main(){
    int q;
    long long int arr[MAXN];
    cin >> n >> q;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        update(i, arr[i]);
    }

    for(int i = 0; i < q; i++){
        int m, a, b;
        cin >> m >> a >> b;

        if(m == 1){
            update(a, b-arr[a]);
            arr[a] = b;
        }else{
            cout << sum(b)-sum(a-1) << endl;
        }
    }

    return 0;
}