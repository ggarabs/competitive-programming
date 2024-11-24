#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> list(n, 0);

    for(int i = 0; i < n; i++) cin >> list[i];

    sort(list.begin(), list.end());

    int cont = 0;
    for(int i = 1; i < n; i++) if(list[i] != list[i-1]) cont++;

    cout << cont+1 << endl;

    return 0;
}