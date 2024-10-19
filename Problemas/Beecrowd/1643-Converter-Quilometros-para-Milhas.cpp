#include <bits/stdc++.h>
#define MAX 25000

using namespace std;

int main(){
	int t; cin >> t;

	vector<int>fib(2, 0);
	fib[0] = 1, fib[1] = 2;

	int it = 1;
	while(fib[it++] < MAX) fib.push_back(fib[it-1] + fib[it-2]);

	while(t--){
		int x, sol = 0; cin >> x;
		for(int i = fib.size()-1; i > 0; i--){
			if(x / fib[i] > 0){
				sol += fib[i-1];
				x %= fib[i];
			}
		}
		cout << sol << endl;
	}
	return 0;
}
