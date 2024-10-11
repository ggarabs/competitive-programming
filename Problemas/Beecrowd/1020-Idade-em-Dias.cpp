#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    
    int anos = n / 365;
    n %= 365;
    
    cout << anos << " ano(s)" << endl;
    
    int meses = n / 30;
    n %= 30;
    
    cout << meses << " mes(es)" << endl;
    
    cout << n << " dia(s)" << endl;
    
    return 0;
}
