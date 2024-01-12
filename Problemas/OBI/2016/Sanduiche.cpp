#include <bits/stdc++.h>
#define MAXN 2000007

using namespace std;

int main(){
	int n, d;
	cin >> n >> d;

	int sanduiche[MAXN];

	for(int i = 1; i <= n; i++) cin >> sanduiche[i];
	for(int i = n+1; i <= 2*n-1; i++) sanduiche[i] = sanduiche[i-n];

	int l = 1, r = 1;
	long long int cont = 0, sum = sanduiche[1];

	while(l <= r && l <= n && r <= 2*n-1){
		if(sum == d && r-l >= n) cont++;
		if(sum < d){
			r++;
			sum += sanduiche[r];
		}else{
			sum -= sanduiche[l];
			if(l == r){
				r++;
				sum = sanduiche[r];
			}
			l++;
		}
	}

	cout << cont << endl;

	return 0;
}
