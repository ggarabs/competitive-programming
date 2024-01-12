#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int main(){
    int n, palitos[MAXN];
    cin >> n;

    for(int i = 0; i < n; i++) cin >> palitos[i];

    sort(palitos, palitos+n);

    for(int i = n-1; i >= 2; i--){
        if(palitos[i] < palitos[i-1]+palitos[i-2] && palitos[i-1] < palitos[i]+palitos[i-2] && palitos[i-2] < palitos[i]+palitos[i-1]){
            cout << palitos[i-2] << " " << palitos[i-1] << " " << palitos[i] << endl;
            break;
        }
    }

    return 0;
}