#include <bits/stdc++.h>
#define MAXV 57

using namespace std;

int duration[2*MAXV], dp[2*MAXV][MAXV][MAXV][MAXV], cart[3];
int n, k;

int solve(int index, int cart[3]){
	if(dp[index][cart[0]][cart[1]][cart[2]] != -1) return dp[index][cart[0]][cart[1]][cart[2]];
	if(index >= n) return 0;

	int not_take = solve(index+1, cart), take = 0;

	for(int i = 0; i < 3; i++){
		if(cart[i] >= duration[index]){
			cart[i] -= duration[index];
			take = max(take, duration[index] + solve(index+1, cart));
			cart[i] += duration[index];
		}
	}

	return dp[index][cart[0]][cart[1]][cart[2]] = max(take, not_take);
}

int main(){
	cin >> n >> k;

	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < n; i++) cin >> duration[i];

	for(int i = 0; i < k; i++) cin >> cart[i];

	cout << solve(0, cart) << endl;

	return 0;
}
