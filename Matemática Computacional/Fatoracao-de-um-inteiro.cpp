#include <bits/stdc++.h>

using namespace std;

// O(sqrt N)

int main(){
    int n;
    cin >> n;

    vector <int> fatores;

    for(int i = 2; i*i <= n; i++){
        while(n % i == 0){
            fatores.push_back(i);
            n /= i;
        }
    }

    if(n > 1) fatores.push_back(n);

    return 0;
}