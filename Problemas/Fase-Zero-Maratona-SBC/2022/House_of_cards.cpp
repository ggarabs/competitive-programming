#include <bits/stdc++.h>
#define MAXV 1e9

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;

unsigned long long int binary_search(unsigned long long int x){
    long long int ini = 0, fim = MAXV, meio;
    while(ini <= fim){
        meio = (ini+fim)/2;

        unsigned long long int currCards = 3*meio*meio + meio;
        if(currCards > 2*x) fim = meio-1;
        else if(currCards == 2*x) return meio;
        else ini = meio+1;
    }

    return fim;
}

int main(){ _
    int t; cin >> t;

    for(int i = 0; i < t; i++){
        unsigned long long int cards;
        cin >> cards;

        cout << (unsigned long long int) binary_search(cards) << endl;
    }

    return 0;
}
