#include <bits/stdc++.h>
#define MAXN 200007
#define MAXV 1000000007

using namespace std;

long long int a[MAXN];

int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;

		long long int array_sum = 0;

		for(int i = 0; i < n; i++){
			cin >> a[i];
			array_sum += a[i];
		}

		long long int sum = 0, ans = 0;

		for(int i = 0; i < n; i++){
			sum = max(a[i], sum+a[i]);
			ans = max(ans, sum);
		}

		while(k--){
			array_sum += ans;
			array_sum %= MAXV;
			ans *= 2;
			ans %= MAXV;
		}

		while(array_sum < 0){
			array_sum += MAXV;
		}

		cout << array_sum << endl;
	}

		return 0;
}
