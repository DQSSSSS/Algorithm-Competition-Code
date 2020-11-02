#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int n,m;
struct haha {
    int d,t;
}b[SZ];

bool cmp(haha a,haha b) { return a.d < b.d; }

int a[SZ],c[SZ];

bool check(int mid) {
    int sum = 0;
    for(int i = 1;i <= n;i ++) sum += a[i];
    for(int i = 1;i <= n;i ++) c[i] = a[i];
    if(mid >= 2*sum) return true;
    int x = 2*sum - mid;
    for(int i = m,now = mid;i >= 1;i --) {
        if(b[i].d > mid) continue;
        now = min(now,b[i].d);
        int id = b[i].t;
        int d = min(c[id],now);
        c[id] -= d;
        now -= d;
        x -= d;
    }
    if(x <= 0) return true;
    return false;
}

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int i = 1;i <= m;i ++) b[i].d = read(),b[i].t = read();
    sort(b+1,b+1+m,cmp);
    int l = 0,r = 4e5+1;
    while(r-l>1) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
}
