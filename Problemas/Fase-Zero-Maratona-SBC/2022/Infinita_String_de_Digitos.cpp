#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

using namespace std;

typedef unsigned long long int ulli;

string toString(ulli x){
    string aux = "";
    stack <int> p;
    while(x > 0){
        p.push(x % 10);
        x /= 10;
    }
    while(!p.empty()){
        aux += p.top()+'0';
        p.pop();
    }
    if(aux == "") aux = "0";
    return aux;
}

bool isGreater(string a, string b){
    for(int i = 0; i < a.size(); i++){
        if(a[i] < b[i]) return false;
        else if(a[i] > b[i]) return true;
    }
    return false;
}

ulli findFirst(ulli x){
    ulli sum = 0, pot = 1;

    for(int i = 0; i <= 18; i++){
        if(x >= 10*pot-1){
            sum += 9*(i+1)*pot;
        }else{
            sum += (x+1-pot)*(i+1);
            break;
        }
        pot *= 10;
    }
    return sum;
}

ulli binarySearch(ulli x, ulli maxv){
    ulli ini = 0, fim = maxv, meio;
    while(ini <= fim){
        meio = (ini+fim)/2;
        ulli first = findFirst(meio);

        if(first == x) return meio;
        else if(first > x) fim = meio-1;
        else ini = meio+1;
    }
    return fim;
}

int main(){ _
    int k; cin >> k;

    ulli l, r; cin >> l >> r;

    ulli first = binarySearch(l, l);

    if(findFirst(first) != l) first++;

    ulli cont = toString(first).size() - findFirst(first) + l - 1, it = 0;
    string v = "";

    for(;it <= r-l;){
        string aux = toString(first);
        while(cont <= aux.size()-1 && it <= r-l){
            v += aux[cont++];
            it++;
        }
        if(it <= r-l){
            first++;
            cont = 0;
        }
    }

    string max_string = "";

    for(int i = 0; i < k && i < v.size(); i++) max_string += v[i];

    string ans = max_string;

    for(int i = k; i < v.size(); i++){
        max_string.erase(max_string.begin()+0);
        max_string.push_back(v[i]);
        if(isGreater(max_string, ans)) ans = max_string;
    }

    while(ans[0] == '0' && ans.size() > 1){
        ans.erase(ans.begin()+0);
    }

    cout << ans << endl;

    return 0;
}