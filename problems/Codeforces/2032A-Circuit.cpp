#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int num[2] = {0, 0};
        for(int i = 0; i < 2*n; i++){
            int aux; cin >> aux;
            num[aux]++;
        }

        cout << num[1]%2 << " " ;

        if(num[0] >= num[1]) cout << num[1];
        else cout << num[0];

        cout << endl;
    }
}
