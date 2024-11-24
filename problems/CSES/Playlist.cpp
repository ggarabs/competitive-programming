#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    map <int, int> songs;
    vector <int> list(n, 0);

    int ans = 0, ini = 0;

    for(int i = 0; i < n; i++){
        cin >> list[i];

        while(songs.find(list[i]) != songs.end()){
            songs.erase(list[ini]);
            ini++;
        }

        songs[list[i]] = i;
        
        ans = max(ans, (int)songs.size());
    }

    cout << ans << endl;

    return 0;
}