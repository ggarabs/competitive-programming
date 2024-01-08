#include <bits/stdc++.h>

using namespace std;

int main(){
    int inf[8];
    for(int i = 0; i < 8; i++){
        cin >> inf[i];
        if(inf[i] == 9){
            cout << 'F' << endl;
            return 0;
        }
    }
    cout << 'S' << endl;
    return 0;
}