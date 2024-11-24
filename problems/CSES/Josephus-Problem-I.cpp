#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    vector <int> list(n, 0);
    for(int i = 1; i <= n; i++) list[i-1] = i;

    int i = 1;
    while(true){
        if(i == (int)list.size()){
            cout << list[i-1] << endl;
            break;
        }
        cout << list[i] << " ";
        list.push_back(list[i-1]);
        i += 2;
    }

    return 0;
}