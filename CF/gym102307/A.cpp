#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
const int INF = 1e9 + 10;
const LL mod = 1e9 + 7;
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

struct frac {
    int x,y;
    frac(int _x=0,int _y=1) {
        x = _x; y = _y;
        int d = __gcd(x,y);
        x /= d; y /= d;
        if(y<0) y=-y,x=-x;
    }

    frac operator -(frac o) { return frac(x-o.x,y-o.y); }
}a[SZ];

bool operator <(frac a,frac o) {
    if(o.x != a.x) return a.x < o.x;
    return a.y < o.y;
}

int b[SZ];

int main() {
    int T= read();
    while(T --) {
        int n = read();
        map<frac,int> mp;
        LL cz = 0,px = 0;
        for(int i = 1;i <= n;i ++) b[i] = 0;
        for(int i = 1;i <= n;i ++) {
            int x1 = read(),y1 = read();
            int x2 = read(),y2 = read();
            if(x1 == x2 || y1 == y2) {
                b[i] = 1;
                if(x1 == x2) cz ++;
                else px ++;
            }
            else {
                mp[a[i] = frac(y1-y2,x1-x2)] ++;
            }
        }

        LL ans = 0;
        for(int i = 1;i <= n;i ++) {
            if(b[i] == 1) continue;
            frac x = frac(-a[i].y,a[i].x);
            ans += mp[x];
        }
        ans /= 2;
        ans += 1ll * cz * px;
        printf("%lld\n",ans);
    }
}
