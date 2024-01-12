#include <bits/stdc++.h>
#define MAXN 1000007

using namespace std;

bool comp(int a, int b){ return a > b; }

int sum(int x){
    int copy = x, sum = 0;
    while(copy > 0){
        sum += copy % 10;
        copy /= 10;
    }
    return sum;
}

int main(){
    int n, k;
    cin >> n >> k;

    int pollen[MAXN];

    for(int i = 0; i < n; i++){
        cin >> pollen[i];
    }

    sort(pollen, pollen+n, comp);

    for(int i = 0; i < k-1; i++){
        pollen[0] -= sum(pollen[0]);
        sort(pollen, pollen+n, comp);
    }

    cout << sum(pollen[0]) << endl;

    return 0;
}