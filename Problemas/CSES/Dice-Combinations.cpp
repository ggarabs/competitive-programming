#include <bits/stdc++.h>
#define MAXN 1000107
#define mod %
#define INT 1000000007

using namespace std;

int ans[MAXN];

int main(){
    int n;
    cin >> n;

    ans[0] = 1;

    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            ans[i+j] = (ans[i+j]+ans[i]) mod INT;
        }
    }

    cout << ans[n] << endl;

    return 0;
}