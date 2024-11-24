#include <bits/stdc++.h>
#define MAXN 26

using namespace std;

int ocurr[MAXN];

int main(){
    string original; cin >> original;

    char central_letter = ' ';
    for(int i = 0; i < (int)original.size(); i++) ocurr[original[i]-'A']++;
    for(int i = 0; i < 26; i++){
        if(ocurr[i] % 2 == 1){
            if(central_letter == ' ') central_letter = i+'A';
            else{
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
        ocurr[i] /= 2;
    }

    for(int i = 0; i < 26; i++) for(int j = 0; j < ocurr[i]; j++) cout << (char)(i+'A');
    if(central_letter != ' ') cout << central_letter;
    for(int i = 25; i >= 0; i--) for(int j = 0; j < ocurr[i]; j++) cout << (char)(i+'A');

    cout << endl;

    return 0;
}