#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		long long int n, curr_sum = 0, ind = 0; cin >> n;
		map <long long int, int> sums;
		sums[0] = 0;
		long long int ans = 0;
		for(int i = 1; i <= n; i++){
			int aux; cin >> aux;
			curr_sum += aux;
			if(sums.find(curr_sum) != sums.end() && sums[curr_sum] >= ind){
				ind = i;
				ans++;
			}
			sums[curr_sum] = i;
		}
		cout << ans << endl;
	}
}
