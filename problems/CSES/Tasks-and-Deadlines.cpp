#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int n; cin >> n;

    vector <pair<int, int>> tasks(n, {0, 0});
    for(int i = 0; i < n; i++) cin >> tasks[i].first >> tasks[i].second;

    sort(tasks.begin(), tasks.end());

    lli time = 0, ans = 0;
    for(int i = 0; i < n; i++){
        time += tasks[i].first;
        ans += tasks[i].second - time;
    }

    cout << ans << endl;

    return 0;
}