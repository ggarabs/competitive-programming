#include <bits/stdc++.h>

using namespace std;

bool primo(int x){
	for(int i = 2; i <= sqrt(x); i++){
		if(x % i == 0) return false;
	}
	return true;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
	    int num;
	    cin >> num;

	    if(primo(num)) cout << "Prime" << endl;
	    else cout << "Not Prime" << endl;
    }

    return 0;
}
