#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int SZ = 500010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct Point {
    LL x,y;
    void Read() { x=read(); y=read(); }
    Point operator -(Point o) { return (Point){x-o.x,y-o.y}; }
    bool operator ==(Point o) { return o.x==x&&o.y==y; }
};

bool isCommon(Point a,Point b,Point c) {
    Point x = a-b; Point y = a-c;
    if(y.x*x.y==x.x*y.y) return true;
    return false;
}

int main() {
    int T = read();
    while(T --) {
        Point a,b,c;
        a.Read();
        b.Read();
        c.Read();
        if(c==a||c==b) puts("YES");
        else if(isCommon(a,b,c)) {
            if(a.x!=b.x) {
                if((b.x-a.x>0)^(c.x-a.x>0)) puts("NO");
                else puts("YES");
            }
            else {
                if((b.y-a.y>0)^(c.y-a.y>0)) puts("NO");
                else puts("YES");
            }
        }
        else puts("NO");
    }
    return 0;
}
