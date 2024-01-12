#include <bits/stdc++.h>
#define MAXN 1000007

using namespace std;

long long int arrows[MAXN];

int main(){
    int n, ans = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        int h;
        cin >> h;

        arrows[h-1]++;
        if(arrows[h] == 0) ans++;
        else arrows[h]--;
    }

    cout << ans << endl;

    return 0;
}