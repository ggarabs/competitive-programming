#include <bits/stdc++.h>

using namespace std;

int main(){
	string aux;
	int dia0, h0, m0, s0;
	int dia1, h1, m1, s1;

	cin >> aux >> dia0;
	cin >> h0 >> aux >> m0 >> aux >> s0;
	cin >> aux >> dia1;
	cin >> h1 >> aux >> m1 >> aux >> s1;

	int ans = (dia1-dia0)*24*60*60 + (h1-h0)*60*60 + (m1-m0)*60 + s1-s0;

	cout << ans / (24*60*60) << " dia(s)" << endl;
	ans %= (24*60*60);
	cout << ans / (60*60) << " hora(s)" << endl;
	ans %= (60*60);
	cout << ans / 60 << " minuto(s)" << endl;
	ans %= 60;
	cout << ans << " segundo(s)" << endl;

	return 0;
}
