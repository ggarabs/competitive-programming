#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

int tiles[MAXN];

int solve(int l , int r, int n){
    if(n == 0) return 0;
    if((n > l && n > r) || tiles[n] == 1) return solve(l, r, n-1);
    if(tiles[n] == 0 && l >= n && r >= n){
        return max(n+solve(l-n, r, n-1), n+solve(l, r-n, n-1));
    }
    if(tiles[n] == 0 && r >= n){
        return n+solve(l, r-n, n-1);
    }
    if(tiles[n] == 0 && l >= n){
        return n+solve(l-n, r, n-1);
    }
    return solve(l, r, n-1);
}

int main(){
    int n, k, e;
    cin >> n >> k >> e;

    tiles[k] = 1;

    int l = e;
    int r = n - l - k;

    cout << n-k-solve(l, r, max(l,r)) << endl;

    return 0;
}