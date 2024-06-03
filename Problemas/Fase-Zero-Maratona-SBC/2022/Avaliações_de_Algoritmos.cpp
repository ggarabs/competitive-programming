#include <bits/stdc++.h>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    int n; cin >> n;
    getchar();

    for(int i = 0; i < n; i++){
        string nome; getline(cin, nome);
        string notas; getline(cin, notas);
        notas += ' ';
        vector <float> grade;
        float aux = 0.0;
        for(int j = 0; j < notas.size(); j++){
            if(notas[j] == '.') continue;
            else if(notas[j] == ' '){
                grade.push_back(aux/10.0);
                aux = 0.0;
            }else{
                aux = 10.0*aux + (notas[j]-'0');
            }
        }
        sort(grade.begin(), grade.end(), greater<int>());
        cout << nome << ": ";
        cout.precision(1);
        cout.setf(ios::fixed);
        if(grade.size() == 1) cout << (float)(grade[0]/(2.0)) << endl;
        else if(grade.size() == 2) cout << (float)((grade[0]+grade[1])/(2.0)) << endl;
        else cout << (float)((grade[0]+grade[1]+grade[2])/(3.0)) << endl;            
    }

    return 0;
}