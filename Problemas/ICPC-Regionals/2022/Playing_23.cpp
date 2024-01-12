#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, deck[14], pts[14];
    cin >> n;

    deck[0] = 0;
    for(int i = 1; i <= 13; i++){
        deck[i] = 4;
        pts[i] = min(10, i);
    }

    int j_pts = 0, m_pts = 0, a, b;

    cin >> a >> b;
    deck[a]--;
    deck[b]--;
    j_pts += pts[a]+pts[b];

    cin >> a >> b;
    deck[a]--;
    deck[b]--;
    m_pts += pts[a]+pts[b];

    for(int i = 0; i < n; i++){
        int card;
        cin >> card;
        deck[card]--;
        j_pts += pts[card];
        m_pts += pts[card];
    }

    int sol1=-1, sol2=-1;

    for(int p = 24-j_pts; p <= 9; p++){
        if(deck[p]){
            sol1 = p;
            break;
        }
    }

    int v = 10;
    while(24-j_pts == 10 && sol1 == -1 && v <= 13){
        if(deck[v]){
            sol1 = v;
            break;
        }
        v++;
    }

    if(23-m_pts <= 9 && deck[23-m_pts]) sol2 = 23-m_pts;

    v = 10;
    while(23-m_pts == 10 && sol2 == -1 && v <= 13){
        if(deck[v]){
            sol2 = v;
            break;
        }
        v++;
    }

    if(sol2 != -1){
        if(sol1 != -1) cout << min(sol1, sol2) << endl;
        else cout << sol2 << endl;
    }else{
        if(sol1 != -1){
            if(m_pts+pts[sol1] > 23) cout << -1 << endl;
            else cout << sol1 << endl;
        }else cout << -1 << endl;
    }

    return 0;
}