#include <bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;

	while(t--){
		int n; cin >> n;

		vector <int> array;

		for(int i = 0; i < n; i++){
			int value; cin >> value;
			array.push_back(value);
		}

		sort(array.begin(), array.end());

		int mid = n/2, resp = 1;
		if(n % 2 == 0) mid--;

		while(mid < n-1 && array[mid] == array[mid+1]){
			resp++;
			mid++;
		}

		cout << resp << endl;
	}

	return 0;
}
