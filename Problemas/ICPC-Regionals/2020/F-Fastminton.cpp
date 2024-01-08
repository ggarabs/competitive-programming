#include <bits/stdc++.h>

using namespace std;

int main(){
    string res;
    cin >> res;

    int pts[2] = {0, 0}, games[2] = {0, 0}, server = 0;
    bool end = false;

    for(int i = 0; i < (int)res.size(); i++){
        if(!end && res[i] == 'S'){
            pts[server]++;
            if(pts[server] >= 5 && abs(pts[server]-pts[(server+1)%2]) >= 2 || pts[server] == 10){
                games[server]++;
                if(games[server]==2) end = true;
                pts[0] = pts[1] = 0;
            }
        }else if(!end && res[i] == 'R'){
            pts[(server+1)%2]++;
            if((pts[(server+1)%2] >= 5 && abs(pts[server]-pts[(server+1)%2]) >= 2) || pts[(server+1)%2] == 10){
                games[(server+1)%2]++;
                if(games[(server+1)%2]==2) end = true;
                pts[0] = pts[1] = 0;
            }
            server = (server+1)%2;
        }else if(res[i] == 'Q'){
            if(games[0] >= 2){
                cout << games[0] << " (winner) - " << games[1] << endl;
            }else if(games[1] >= 2){
                cout << games[0] << " - " << games[1] << " (winner)" << endl;
            }else{
                if(server == 0){
                    cout << games[0] << " (" << pts[0] << "*) - " << games[1] << " (" << pts[1] << ")" << endl;
                }else{
                    cout << games[0] << " (" << pts[0] << ") - " << games[1] << " (" << pts[1] << "*)" << endl;
                }
            }
        }
    }

    return 0;
}