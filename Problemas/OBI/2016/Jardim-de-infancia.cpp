#include <bits/stdc++.h>

using namespace std;

struct point{
    int x, y;
    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    point operator+(const point &o) {return point{x+o.x, y+o.y}; }
    point operator-(const point &o) {return point{x-o.x, y-o.y}; }
    long long operator*(const point &o) {return 1ll*x*o.x + 1ll*y*o.y; }
    long long operator/(const point &o) {return 1ll*x*o.y - 1ll*y*o.x; }
};

bool is_acute(point a, point c, point b){
    return (a-c)*(b-c) > 0;
}

bool are_collinear(point a, point c, point b){
    return (a-c)/(b-c) == 0;
}

bool are_perpendicular(point a, point b, point c, point d){
    return (a-b)*(c-d) == 0;
}

long long dist(point a, point b){
    point c = a-b;
    return c.y*c.y+c.x*c.x;
}

int cw(point a, point c, point b){
    if((a-c)/(b-c) > 0) return 1;
    if((a-c)/(b-c) == 0) return 0;
    return -1;
}

point midpoint(point a, point b){
    return {(a.x+b.x),(a.y+b.y)};
}

int main(){
    point p[8];

    for(int i = 1; i <= 7; i++) cin >> p[i].x >> p[i].y;

    char ans = 'S';

    if(!is_acute(p[2], p[1], p[3])) ans = 'N';
    if(dist(p[2],p[1]) != dist(p[3],p[1])) ans = 'N';
    if(!are_collinear(p[2], p[3], p[4]) || !are_collinear(p[3], p[4], p[5])) ans = 'N';
    if(midpoint(p[2],p[3]).x != midpoint(p[4], p[5]).x || midpoint(p[2],p[3]).y != midpoint(p[4], p[5]).y) ans = 'N';
    if(dist(p[2], p[3]) <= dist(p[4], p[5])) ans = 'N';
    if(!are_perpendicular(p[4], p[6], p[2], p[3]) || !are_perpendicular(p[5], p[7], p[2], p[3])) ans = 'N';
    if(dist(p[4], p[6]) != dist(p[5], p[7])) ans = 'N';
    if(cw(p[1],p[2],p[3]) == cw(p[6],p[2],p[3])) ans = 'N';
    if(cw(p[2],p[6],p[1]) == cw(p[3],p[6],p[1])) ans = 'N';

    cout << ans << endl;

    return 0;
}