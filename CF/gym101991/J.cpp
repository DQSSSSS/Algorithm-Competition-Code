#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

struct vec {
    double x,y,z;
    vec(double xx=0,double yy=0,double zz=0) : x(xx),y(yy),z(zz) { }
    void read() { x = ::read(),y = ::read(),z = ::read(); }
    double length() { return sqrt(x*x+y*y+z*z); }
    vec operator /(double d) { return vec(x/d,y/d,z/d); }
    vec operator *(double d) { return vec(x*d,y*d,z*d); }
    vec operator -(vec o) { return vec(x-o.x,y-o.y,z-o.z); }
    vec operator +(vec o) { return vec(x+o.x,y+o.y,z+o.z); }
    void print() { printf("%.6f %.6f %.6f\n",x,y,z); }
};

vec operator *(vec a,vec b) {
    return vec(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}

double dianji(vec a,vec b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

int main() {
    freopen("jupiter.in","r",stdin);
    int T = read();
    while(T --) {
        vec N,A;
        N.read(); A.read();
        double L = read(),H = read();
        vec F = A * N;
        F = F / F.length() * A.length() / 2.0 * sqrt(3);
        vec B = A*(-0.5)+F;
        vec C = A*(-0.5)-F;

        A.z += H; B.z += H; C.z += H;
        printf("%.6f %.6f %.6f\n",A.length(),C.length(),B.length());
    }
}

