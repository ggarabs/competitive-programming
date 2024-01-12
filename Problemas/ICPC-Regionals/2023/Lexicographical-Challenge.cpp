#include <bits/stdc++.h>
#define MAXN 100007

using namespace std;

int main(){
    string s;
    int k;

    cin >> s >> k;

    string aux[MAXN];

    for(int i = 0; i < (int)s.size(); i++) aux[i%k] += s[i];

    for(int i = 0; i < k; i++) sort(aux[i].begin(), aux[i].end());

    for(int i = 0; i < (int)s.size(); i++) s[i] = aux[i%k][i/k];

    cout << s << endl;

    return 0;
}