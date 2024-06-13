#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

using namespace std;

int main(){ _
    int n, k; cin >> n >> k;
    vector <int> notas(n, 0);

    for(int i = 0; i < n; i++) cin >> notas[i];

    sort(notas.begin(), notas.end());

    cout << notas[n-k] << endl;

    return 0;
}