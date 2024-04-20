#include <bits/stdc++.h>
#define MAXN 8

using namespace std;

int main(){
    int v[MAXN], impar = 0;

    for(int i = 0; i < 7; i++){
        int aux;
        cin >> aux;
        if(aux == 1) impar++;
    }

    int seg; cin >> seg;

    if((impar % 2 == 1 && seg == 0) || (impar % 2 == 0 && seg == 1)) cout << "S" << endl;
    else cout << "N?" << endl;

    return 0;
}