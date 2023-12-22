#include <bits/stdc++.h>

using namespace std;

struct point {
    int x, y;
    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    point operator+(const point &o) {return point{x+o.x, y+o.y}; } // soma de vetores
    point operator-(const point &o) {return point{x-o.x, y-o.y}; } // soma de vetores
	long long operator * (const point& o) { return 1ll*x*o.x + 1ll*y*o.y; } // dot - produto escalar
	long long operator / (const point& o) { return 1ll*x*o.y - 1ll*y*o.x; } // cross - produto vetorial
};

bool are_collinear(point a, point c, point b){
    return (a-c) / (b-c) == 0;
}

bool cw(point a, point c, point b){ // counterwise
    return (a-c) / (b-c) < 0;
}

bool ccw(point a, point c, point b){ // counterclockwise
    return (a-c) / (b-c) > 0;
}

long long area(vector <point> polygon){
    point base = polygon[0];
    long long ans = 0;
    for(int i = 2; i < polygon.size(); i++) ans += (polygon[i]-base) / (polygon[i-1]-base);
    return abs(ans/2.0);
}

int main(){
    return 0;
}