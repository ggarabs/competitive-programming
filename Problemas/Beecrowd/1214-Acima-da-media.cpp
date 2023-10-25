#include <bits/stdc++.h>
#define MAXN 1007

using namespace std;

int main(){
	int c;
	cin >> c;

	for(int i = 0; i < c; i++){
		int n, aluno[MAXN];
		cin >> n;

		double media = 0;

		for(int j = 0; j < n; j++){
			cin >> aluno[j];
			media += aluno[j];
		}

		media /= n;

		int acima = 0;

		for(int j = 0; j < n; j++) if(aluno[j] > media) acima++;

		cout.precision(3);
		cout.setf(ios::fixed);

		cout << (100*(double)acima)/n << "%" << endl;
	}
	return 0;
}
