#include <bits/stdc++.h>
#define MAXN 10007

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

            map <int, int> v;
            for(int i = 0; i < n; i++){
                if(v.find(erro[i]) == v.end()) v[erro[i]] = 0;
                v[erro[i]]++;
            }

            v[erro[j]]--;
            bool cor = true;

            for(int i = 1; i < n; i++){
                if(i == j) continue;
                if(v.find(abs(num-palpites[i])) != v.end()){
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