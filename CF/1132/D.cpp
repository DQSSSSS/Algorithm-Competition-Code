#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int mod = 998244353;
const int INF = 1e9 + 10;
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

int n,m;
LL a[SZ],b[SZ];
vector<pii> g[SZ];

bool check(LL mid) {
    for(int i = 0;i < m;i ++) g[i].clear();
    for(int i = 1;i <= n;i ++) {
        LL x = a[i] / b[i];
        if(x < m) g[x].push_back(make_pair(a[i],b[i]));
    }
    LL t = 0;
    for(int i = 0;i < m;i ++) {
        t ++;
        for(pii p : g[i]) {
            LL x = p.first,y = p.second;
            LL k = (x /y*y+y-x + mid - 1) / mid;
        //    cout << x << " " << y << " " << k << " "<< mid << endl;
            x += k * mid;
            t -= k;
            if(x / y < m) g[x/y].push_back(make_pair(x,y));
        }
        if(t < 0) return false;
        g[i].clear();
    }
    return true;
}

int main() {
    n = read(),m = read() - 1;
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= n;i ++) b[i] = read();
    bool flag = 0;
    for(int i = 1;i <= n;i ++) {
        if(a[i] / b[i] < m) flag = 1;
    }
    if(!flag) {
        puts("0");
        return 0;
    }

    LL l = 0,r = 3e12;
    while(r - l > 1) {
        LL mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    //check(4);
    if(r == 3e12) r = -1;
    cout << r << endl;
}
/**
2 1
2 10
3 15


*/
