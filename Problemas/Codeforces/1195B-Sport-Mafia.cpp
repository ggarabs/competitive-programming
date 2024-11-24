#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
	lli n, k; cin >> n >> k;

	lli ini = 1, fim = n;
	while(ini <= fim){
		lli mid = (ini+fim)/2;

		lli x = (1+mid)*mid/2;
		x -= (n-mid);

		if(x == k){
			cout << n-mid << endl;
			break;
		}
		if(x > k) fim = mid-1;
		else ini = mid+1;
	}

	return 0;
}
