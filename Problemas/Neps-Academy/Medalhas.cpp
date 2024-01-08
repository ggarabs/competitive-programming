#include <bits/stdc++.h>
#define MAXN 200007

using namespace std;

int main(){
    int a, v;
    cin >> a >> v;

    pair<long long int, int> medalhas[MAXN];

    for(int i = 0; i < a; i++){
        cin >> medalhas[i].first;
        medalhas[i].second = 0;
    }

    for(int i = a; i < v+a; i++){
        cin >> medalhas[i].first;
        medalhas[i].second = 1;
    }

    sort(medalhas, medalhas+(a+v));

    int i;

    for(i = a+v-1; i >= 1; i--){
        if(medalhas[i].second != medalhas[i-1].second) break;
    }

    cout << a+v-i-1 << endl;

    return 0;
}