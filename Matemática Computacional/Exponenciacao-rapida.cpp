#include <bits/stdc++.h>

using namespace std;

// Exponenciação rápida em O(log N)

int Exp(int x, int n){
    if(n == 0) return 1;

    int t = Exp(x, n/2);

    if(n%2 == 0) return t*t;

    return x*t*t;
}