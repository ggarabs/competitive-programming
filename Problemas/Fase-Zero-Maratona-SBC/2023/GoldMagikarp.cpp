#include <bits/stdc++.h>

using namespace std;

vector <long long int> st;

long long int cast_to_int(string x){
    long long int aux = 0;
    for(int i = 0; i < x.size(); i++){
        aux += (x[i]-'0');
        aux *= 10;
    }
    return aux/10;
}

long long int trata(string x){
    string buffer = "";
    for(int i = 0; i < x.size(); i++) if(x[i] >= '0' && x[i] <= '9') buffer += x[i];
    return cast_to_int(buffer);
}

string obtain_number(string x){
    string buffer = "";
    bool begin = false;
    for(int i = 0; i < x.size(); i++){
        if(begin) buffer += x[i];
        if(begin && (x[i] == ' ' || x[i] == ',' || x[i] == '.') && (i == x.size()-1 || (x[i+1] >= 'a' && x[i+1] <= 'z'))){
            begin = false;
            st.push_back(trata(buffer));
            buffer = "";
        }
        if(begin && (x[i] == ' ' || x[i] == ',' || x[i] == '.') && (i == x.size()-1 || ((x[i+1] == ' ' || x[i+1] == ',' || x[i+1] == '.')))){
            begin = false;
            st.push_back(trata(buffer));
            buffer = "";
        }
        if((x[i] == ' ' || x[i] == ',' || x[i] == '.') && (i+1 < x.size() && x[i+1] >= '0' && x[i+1] <= '9')) begin = true; //mudar
    }
    return buffer;
}

int main(){
    int n;
    cin >> n;

    getchar();

    for(int i = 0; i < n; i++){
        string frase, num;
        getline(cin, frase);
        obtain_number(' ' + frase + ' ');
    }

    bool ans = false;
    for(int i = 0; i < st.size(); i++){
        for(int k = 0; k < 2; k++){
            int cont = 0;
            for(int j = i+1; j < st.size(); j++){
                if(st[i]+(pow(-1, k))*(cont+1) == st[j]) cont++;
                if(cont == 2){
                    ans = true;
                    break;
                }
            }            
        }
    }

    if(ans) cout << 123 << endl;
    else cout << ":)" << endl;

    return 0;
}