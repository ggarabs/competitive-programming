#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

using namespace std;

bool novo_padrao(string placa){
    if(placa.size() != 7) return false;
    bool ans = true;
    for(int i = 0; i < 3; i++) ans &= ('A' <= placa[i] && placa[i] <= 'Z');
    ans &= ('0' <= placa[3] && placa[3] <= '9');
    ans &= ('A' <= placa[4] && placa[4] <= 'Z');
    for(int i = 5; i < 7; i++) ans &= ('0' <= placa[i] && placa[i] <= '9');
    return ans;
}

bool padrao_antigo(string placa){
    if(placa.size() != 8) return false;
    bool ans = true;
    for(int i = 0; i < 3; i++) ans &= ('A' <= placa[i] && placa[i] <= 'Z');
    ans &= placa[3] == '-';
    for(int i = 4; i < 8; i++) ans &= ('0' <= placa[i] && placa[i] <= '9');
    return ans;
}

int main(){ _
    string placa; cin >> placa;

    if(padrao_antigo(placa)) cout << '1' << endl;
    else if(novo_padrao(placa)) cout << '2' << endl;
    else cout << '0' << endl;

    return 0;
}