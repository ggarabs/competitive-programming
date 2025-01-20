#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector <int> ir(n);

    int fim = 0;
    for(int i = 0; i < n; i++){ cin >> ir[i]; fim = max(fim, ir[i]); }

    sort(ir.begin(), ir.end());

    int ini = 0;

    while(ini <= fim){
        int cont = 0, mid = (ini+fim)>>1;
        for(int i = 0; i < ir.size(); i++) cont += (ir[i] >= mid);
        if(mid > cont) fim = mid-1;
        else ini = mid+1;
    }

    cout << fim << endl;

    return 0;
}