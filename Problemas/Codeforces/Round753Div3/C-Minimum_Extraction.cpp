#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector <int> array;

        for(int i = 0; i < n; i++){
            int aux; cin >> aux;
            array.push_back(aux);
        }

        sort(array.begin(), array.end());

        int ans = array[0], aux = array[0];

        for(int i = 1; i < n; i++){
            aux -= array[i];
            array[i] = aux;
            ans = max(ans, aux);
        }

        cout << ans << endl;

    }

    return 0;
}