#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
const int mod = 998244353;
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

int fa[SZ];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

struct edge {
    int u,v;
    LL w;
}l[SZ];

bool cmp(edge a,edge b) {
    return a.w < b.w;
}

int main() {
    freopen("data0.in","r",stdin);
    freopen("data0.out","w",stdout);
    int n = read(),m = read(),k = read();
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read();
        LL z = read();
        l[i] = (edge){x,y,z};
    }
    sort(l+1,l+1+m,cmp);
    int t = 0;
    LL ans = 0;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++) {
        int x = find(l[i].u);
        int y = find(l[i].v);
        if(x != y) {
            if(t+k >= n) break;
            fa[x] = y;
            t ++;
            ans += l[i].w;
        }
    }
    cout << ans << endl;
}
