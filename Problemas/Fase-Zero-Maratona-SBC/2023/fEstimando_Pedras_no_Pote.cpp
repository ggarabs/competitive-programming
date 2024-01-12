#include <bits/stdc++.h>
#define MAXN 10007
#define MAXP 1000000001

using namespace std;

int main(){
    int n, palpites[MAXN], erro[MAXN];
    cin >> n;

    for(int i = 0; i < n; i++) cin >> palpites[i];
    for(int i = 0; i < n; i++) cin >> erro[i];

    set <long long int> sol;
    int num;

    for(int j = 0; j < n; j++){
        for(int k = 0; k < 2; k++){
            num = palpites[0] + pow(-1,k)*erro[j];

            vector <int> v;
            v.resize(MAXP);

            for(int i = 0; i < n; i++) v[erro[i]] = 0;
            for(int i = 0; i < n; i++) v[erro[i]]++;

            v[erro[j]]--;
            bool cor = true;

            for(int i = 1; i < n; i++){
                if(v[abs(num-palpites[i])] != 0){
                    v[abs(num-palpites[i])]--;
                }else{
                    cor = false;
                    break;
                }
            }

            if(cor) sol.insert(num);
        }
    }

    for(set<long long int>::iterator it = sol.begin(); it != sol.end(); it++) cout << *it << endl;

    return 0;
}