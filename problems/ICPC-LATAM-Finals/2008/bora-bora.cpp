#include <bits/stdc++.h>

using namespace std;

int players[10][4][14];
int cards[10];

map<char, int> naipe;

int main(){
    int p, m, n; 

    naipe['C'] = 0;
    naipe['D'] = 1;
    naipe['H'] = 2;
    naipe['S'] = 3;

    while(cin >> p >> m >> n && p && m && n){
        for(int i = 0; i < p; i++){
            for(int j = 1; j <= m; j++){
                int value; char np;
                cin >> value >> np;

                players[i][naipe[np]][value]++;
                cards[i]++;
            }
        }

        queue <pair <int, int>> sq;
        for(int i = p*m+1; i <= n; i++){
            int value; char np;
            cin >> value >> np;

            sq.push({value, naipe[np]});
        }

        pair <int, int> topo = sq.front();
        sq.pop();
        int dir = 1, curr_player = 0;
        bool pula = 0;

        if(topo.first == 12) dir *= -1;
        else if(topo.first == 7){
            for(int k = 0; k < 2; k++){
                players[curr_player][sq.front().second][sq.front().first]++;
                sq.pop();    
            }
            cards[curr_player] += 2;

            pula = 1;
        }else if(topo.first == 1){
            players[curr_player][sq.front().second][sq.front().first]++;
            sq.pop();
            cards[curr_player]++;

            pula = 1;
        }else if(topo.first == 11) pula = 1;

        bool end = 0;

        while(true){
            if(pula){
                curr_player = (curr_player + dir + p) % p;
                pula = 0;
                continue;
            }

            bool find = 0;
            for(int i = 13; i >= 1; i--){
                for(int j = 3; j >= 0; j--){
                    if(players[curr_player][j][i] > 0 && (j == topo.second || i == topo.first)){
                        players[curr_player][j][i]--;
                        cards[curr_player]--;
                        if(cards[curr_player] == 0){
                            end = 1;
                            break;
                        }
                        topo = {i, j};
                        find = 1;
                        break;
                    }
                }
                if(find || end) break;
            }

            if(end){
                cout << curr_player+1 << endl;
                break;
            }

            if(!find){
                pair<int, int> desc = sq.front();
                sq.pop();

                if(desc.second == topo.second || desc.first == topo.first){
                    topo = desc;
                }else{
                    players[curr_player][desc.second][desc.first]++;
                    cards[curr_player]++;
                    curr_player = (curr_player + dir + p) % p;
                    continue;
                }
            }

            if(topo.first == 12){
                dir *= -1;
                curr_player = (curr_player + dir + p) % p;
            }else{
                curr_player = (curr_player + dir + p) % p;
                if(topo.first == 7){
                    for(int i = 0; i < 2; i++){
                        players[curr_player][sq.front().second][sq.front().first]++;
                        sq.pop();    
                    }
                    cards[curr_player] += 2;
    
                    pula = 1;
                }else if(topo.first == 1){
                    players[curr_player][sq.front().second][sq.front().first]++;
                    sq.pop();
                    cards[curr_player]++;
    
                    pula = 1;
                }else if(topo.first == 11){
                    pula = 1;
                }
            }
        }

        for(int i = 0; i < p; i++) for(int j = 0; j < 4; j++) for(int k = 0; k < 14; k++) players[i][j][k] = 0;
        for(int i = 0; i < p; i++) cards[i] = 0;
    }

    return 0;
}