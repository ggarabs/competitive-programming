#include <bits/stdc++.h>

using namespace std;

int main(){
    string nome;
    double salario, vendas, valor;

    cin >> nome >> salario >> vendas;

    valor = salario + 0.15*vendas;

    cout.precision(2);
    cout.setf(ios::fixed);

    cout << "TOTAL = R$ " << valor << endl;

    return 0;

}
