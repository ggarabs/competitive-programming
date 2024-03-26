#include <bits/stdc++.h>
#define MAXN 50007

using namespace std;

int main(){
    int n;
	cin >> n;

    int fator[MAXN], dias[MAXN];

	int id;
	double ans = -1.0;
	for(int i = 0; i < n; i++){
		cin >> fator[i] >> dias[i];

		double atual = fator[i]*log(1.0*dias[i]);

		if(atual > ans){
			ans = atual;
			id = i;
		}
	}
	cout << id << endl;

    return 0;
}
