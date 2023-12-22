#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    while(cin >> n){
        if(n == 0) break;

        int pares = 0;

        for(int i = 0; i < n; i++){
            int c, v;
            cin >> c >> v;

            pares += v/2;
        }

        cout << pares/2 << endl;
    }

    return 0;
}