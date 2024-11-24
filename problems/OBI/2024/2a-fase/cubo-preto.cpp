#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;

	int total = n*n*n, resp1 = (n-2)*(n-2)*(n-2), resp2 = 6*(n-2)*(n-2);

	cout << resp1 << endl << resp2 << endl << total-resp1-resp2-8 << endl << 8 << endl;

	return 0;
}
