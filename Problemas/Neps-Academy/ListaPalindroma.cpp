#include <bits/stdc++.h>
#define MAXN 1000007

using namespace std;

int lista[MAXN];

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> lista[i];

    int l = 0, r = n-1, count = 0;

    while(l < r){
        if(lista[l] == lista[r]){
            l++;
            r--;
        }else if(lista[l] > lista[r]){
            lista[r-1] += lista[r];
            r--;
            count++;
        }else{
            lista[l+1] += lista[l];
            l++;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}