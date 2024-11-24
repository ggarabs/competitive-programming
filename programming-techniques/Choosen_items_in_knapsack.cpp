int sum = target;
for(int i = n; i > 0; i--){
    if(sum >= caramels[i] && dp[i-1][sum-caramels[i]]){
        a.push_back(caramels[i]);
        sum -= caramels[i];
    }else b.push_back(caramels[i]);
}
