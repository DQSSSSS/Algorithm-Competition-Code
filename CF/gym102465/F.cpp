#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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
    int x,y,w;
    Point operator -(Point o) { return (Point){x-o.x,y-o.y}; }
    LL operator ^(Point o) { return 1ll*x*o.y-1ll*y*o.x; }
}a[SZ];

int getXX(Point a) {
    if(a.x>0 && a.y>=0) return 1;
    if(a.x<=0 && a.y>0) return 2;
    if(a.x<0 && a.y<=0) return 3;
    if(a.x>=0 && a.y<0) return 4;
}

bool cmp(Point a,Point b) {
    if(getXX(a) != getXX(b)) return getXX(a) < getXX(b);
    return (a ^ b) > 0;
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i].x = read();
        a[i].y = read();
        a[i].w = read();
    }
    LL ans = 1e18;
    for(int o = 1;o <= n;o ++) {
        vector<Point> b;
        for(int i = 1;i <= n;i ++) {
            if(i != o) {
                Point t = a[i] - a[o]; t.w = a[i].w;
                b.push_back(t);
                t = a[o] - a[i]; t.w = 0;
                b.push_back(t);
            }
        }
        sort(b.begin(),b.end(),cmp);
        vector<LL> sum;
        for(int i = 0;i < b.size();i ++) {
            if(i == 0) sum.push_back(b[i].w);
            else sum.push_back(b[i].w+sum[sum.size()-1]);
        }
        LL S = sum[sum.size()-1];
        for(int i = 0;i < n - 1;i ++) {
            LL t = sum[i+n-1] - (i==0?0:sum[i-1]);
            LL x = S-t;
            LL y = t-b[i].w-b[i+n-1].w;
            ans = min(ans,abs(x-y));
        }

        /*if(o == 3) {
            for(int i = 0;i < 2*(n-1);i ++) printf("%d ",b[i].w); puts("");
            for(int i = 0;i < 2*(n-1);i ++) printf("%lld ",sum[i]); puts("");
        }*/
    }
    cout << ans << endl;
}
