#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

int n,k;

pii work(LL x,LL y,LL dx) {
    if(dx == INF) return make_pair(INF,INF);
    if(y > (x+1)*k || max(0ll,x-(k-dx)) > y * k) return make_pair(INF,INF);
    LL resx,resy;
    if(x * k < y) resx = INF;
    else resx = max(1ll,max(0ll,x-(k-dx))-(y-1)*k);
    if(max(0ll,x-(k-dx)) > (y-1) * k) resy = INF;
    else resy = max(1ll,y-x*k);
    return make_pair(resx,resy);
}

LL a[SZ],b[SZ];

int main() {
    n = read(),k = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= n;i ++) b[i] = read();
    LL resa = 0,resb = 0;
    for(int i = 1;i <= n;i ++) {
        pii x = work(a[i],b[i],resa);
        pii y = work(b[i],a[i],resb);
        resa = min(x.first,y.second);
        resb = min(x.second,y.first);
       // cout << resa << " " << resb << endl;
        if(resa == INF && resb == INF) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
