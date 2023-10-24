#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, h, w;
    cin >> n >> h >> w;

    for(int i = 0; i < n; i++){
        char rain;
        cin >> rain;

        if(rain == 'Y' || w == 0){
            cout << 'Y' << " ";
            w++;
            h--;
        }else cout << 'N' << " ";

        cin >> rain;

        if(rain == 'Y' || h == 0){
            cout << 'Y' << endl;
            h++;
            w--;
        }else cout << 'N' << endl;

    }

    return 0;
}