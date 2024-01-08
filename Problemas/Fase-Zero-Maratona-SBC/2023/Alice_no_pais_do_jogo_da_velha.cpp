#include <bits/stdc++.h>

using namespace std;

int main(){
    string tab;
    cin >> tab;

    if(tab == "XXO" || tab == "OXX") cout << "Alice" << endl;
    else if(tab == "XOX") cout << "*" << endl;
    else cout << "?" << endl;

    return 0;
}