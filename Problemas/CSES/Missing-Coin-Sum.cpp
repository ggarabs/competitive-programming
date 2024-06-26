#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    vector <int> list(n, 0);

    for(int i = 0; i < n; i++) cin >> list[i];

    sort(list.begin(), list.end());

    long long int aux = 1;
    for(int i = 0; i < n; i++){
        if(list[i] > aux){
            cout << aux << endl;
            return 0;
        }

        aux += list[i];
    }

    cout << aux << endl;

    return 0;
}