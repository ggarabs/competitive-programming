#include <bits/stdc++.h>
#define MAXP 57
    
using namespace std;
    
struct point {
    long long x, y;
    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    point operator+(const point &o) {return point{x+o.x, y+o.y}; } // soma de vetores
    point operator-(const point &o) {return point{x-o.x, y-o.y}; } // soma de vetores
    long long operator * (const point& o) { return 1ll*x*o.x + 1ll*y*o.y; } // dot - produto escalar
    long long operator / (const point& o) { return 1ll*x*o.y - 1ll*y*o.x; }
};
    
point polygon[MAXP];
        
int main(){
    int n, p;
    double sum = 0.0;
    
    cin >> n;
    
    for(int k = 0; k < n; k++){
        long long parcial = 0;
        cin >> p;
    
        for(int i = 0; i < p; i++) cin >> polygon[i].x >> polygon[i].y;
    
        for(int i = 2; i < p; i++){
            parcial += (polygon[i]-polygon[0])/(polygon[i-1]-polygon[0]);
        }
        sum += abs(parcial/2.0);
    }
    
    cout << (long long)floor(sum) << endl;
    
    return 0;
}