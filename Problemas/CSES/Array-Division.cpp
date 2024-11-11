#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main(){
    int n, k; cin >> n >> k;

    lli sum = 0;
    vector <int> array(n, 0);
    for(int i = 0; i < n; i++){
        cin >> array[i];
        sum += array[i];
    }

    lli ini = 1, fim = sum;
    while(ini <= fim){
        lli mid = (ini+fim)/2;

        int cuts = 1;
        bool imp = false;
        lli curr_sum = 0;
        
        for(int i = 0; i < n; i++){
            if(array[i] + curr_sum <= mid) curr_sum += array[i];
            else{
                cuts++;
                curr_sum = array[i];
                if(curr_sum > mid){
                    imp = true;
                    break;
                }
            }
        }

        if(cuts > k || imp) ini = mid + 1;
        else fim = mid - 1;
    }

    cout << ini << endl;

    return 0;
}