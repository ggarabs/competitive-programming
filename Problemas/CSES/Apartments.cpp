#include <bits/stdc++.h> 

using namespace std;

int main(){
    int n, m, k; cin >> n >> m >> k;

    vector <int> applicant(n, 0), apartments(m, 0);

    for(int i = 0; i < n; i++) cin >> applicant[i];
    for(int i = 0; i < m; i++) cin >> apartments[i];

    sort(applicant.begin(), applicant.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0, cont = 0;

    while(i < n && j < m){
        if(applicant[i] > apartments[j] + k) j++;
        else if(applicant[i] < apartments[j] - k) i++;
        else{ cont++; i++; j++; }
    }

    cout << cont << endl;

    return 0;
}