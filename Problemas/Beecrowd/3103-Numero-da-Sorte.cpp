#include <bits/stdc++.h>
#define MAXN 107

using namespace std;

int main(){
	int t;
	cin >> t;

	for(int i = 0; i < t; i++){
		string num;

		cin >> num;

		sort(num.begin(), num.end());

		int p = 0;
		while(num[p] == '0') p++;

		swap(num[p], num[0]);

		cout << num << endl;
	}

	return 0;
}
