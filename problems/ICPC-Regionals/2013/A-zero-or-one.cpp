#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, soma = 0;
	cin >> a >> b >> c;

	soma = (a + b + c)%2;

	if(soma == a && soma != b && soma != c) cout << 'A';
	else if(soma != a && soma == b && soma != c) cout << 'B';
	else if(soma != a && soma != b && soma == c) cout << 'C';
	else cout << '*';

	cout << endl;

	return 0;
}
