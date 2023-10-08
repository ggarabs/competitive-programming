#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector <int> lady_chimps;

	for(int i = 0; i < n; i++){
		int h;
		cin >> h;
		lady_chimps.push_back(h);
	}

	int q;
	cin >> q;

	for(int i = 0; i < q; i++){
		int value;
		cin >> value;

		vector<int>::iterator a1 = lower_bound(lady_chimps.begin(), lady_chimps.end(), value);
		vector<int>::iterator a2 = upper_bound(lady_chimps.begin(), lady_chimps.end(), value);

		if(a1 == lady_chimps.begin()) cout << 'X' << ' ';
		else cout << *(--a1) << ' ';

		if(a2 == lady_chimps.end()) cout << 'X' << endl;
		else cout << *a2 << endl;
	}

	return 0;
}
