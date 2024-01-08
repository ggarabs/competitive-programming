#include<bits/stdc++.h>
using namespace std;
const int infinito = 1000000000;
const int maxn = 5e5+10;

int n, a[maxn], s[maxn];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1]+a[i];
    }
    int menor = 0; // comecamos menor como S[0], ou seja, 0
    int resp = -infinito;
    for(int i = 1; i <= n; i++) {
        // vemos se s[i-1] é < que menor, 
        // se for, o substituimos
        menor = min(menor,s[i-1]);
        resp = max(resp,s[i]-menor);
    }
    cout << resp << endl;
}
