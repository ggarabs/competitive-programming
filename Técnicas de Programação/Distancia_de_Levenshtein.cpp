#include <bits/stdc++.h>
#define MAXN 5

using namespace std;

int levenshtein(string orig, string tent){
    int dp[orig.size()+1][tent.size()+1];
    for(int i = 0; i <= orig.size(); i++) dp[i][0] = i;
    for(int i = 0; i <= tent.size(); i++) dp[0][i] = i;

    for(int i = 1; i <= orig.size(); i++){
        for(int j = 1; j <= tent.size(); j++){
            if(orig[i-1] == tent[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
        }
    }

    return dp[orig.size()][tent.size()];
}