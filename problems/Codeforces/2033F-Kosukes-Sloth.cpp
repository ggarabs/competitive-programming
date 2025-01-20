#include <bits/stdc++.h>
#define lli long long int

const int INF = 1e9+7;

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        lli n;
        int k; cin >> n >> k;

        lli cont = 1;
        lli prev = 0, curr = 1, aux;

        while(curr % k != 0){
            cont = (cont%INF + 1)%INF;
            aux = prev % k;
            prev = curr % k;
            curr = (aux%k + curr%k)%k;
        }

        cont %= INF;

        cout << (cont*(n%INF))%INF << endl;

    }
    return 0;
}