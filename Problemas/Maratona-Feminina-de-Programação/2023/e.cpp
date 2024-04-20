#include <bits/stdc++.h>
#define MAXN 200007
#define MAXV 200000000000007

using namespace std;

long long int n, p, a[MAXN];

long long int busca_binaria(long long int ini, long long int fim, int x){
    long long int mid;
    while(ini <= fim){
        mid = (ini+fim)/2;
        long long int pizzas = 0;
        for(int i = 0; i < n; i++) pizzas += (mid/a[i]);
        if(pizzas >= x) fim = mid-1;
        else ini = mid+1;
    }
    return ini;
}

int main(){
    cin >> n >> p;

    for(int i = 0; i < n; i++) cin >> a[i];
    
    long long int index = busca_binaria(0, MAXV, p);

    cout << (long long int)index << endl;

    return 0;
}