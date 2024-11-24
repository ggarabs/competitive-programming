#include <bits/stdc++.h>

using namespace std;

int main(){
	string a, b; cin >> a >> b;

	int la = 0, lb = 0, ra = a.size()-1, rb = b.size()-1;

	while(a[la] == b[lb] && la < a.size() && lb < b.size()){ la++; lb++; }
	while(a[ra] == b[rb] && ra >= 0 && rb >= 0 && ra >= la && rb >= lb){ ra--, rb--; }

	cout << max(rb - lb + 1, 0) << endl;

	return 0;
}
