#include <bits/stdc++.h>

using namespace std;

long long int sum;
vector <int> apples;

long long int solve(vector <int> group, int ind){
    if(ind == 0){
        long long int localSum = 0;
        for(int i = 0; i < group.size(); i++) localSum += group[i];
        return abs(2*localSum - sum);
    }

    long long int not_insert = solve(group, ind-1);

    group.push_back(apples[ind-1]);

    return min(not_insert, solve(group, ind-1));
}

int main(){
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        int aux; cin >> aux;
        apples.push_back(aux);
        sum += apples[i];
    }

    vector <int> group;

    cout << solve(group, n) << endl;

    return 0;
}