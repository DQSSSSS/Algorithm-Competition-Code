#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
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

struct edge {
    int f,t,d;
}l[SZ];

bool cmp(edge a,edge b) { return a.d < b.d; }

int fa[SZ];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
    int c = read(),m = read(),n = read();
    for(int i = 1;i <= m;i ++) {
        l[i].f = read();
        l[i].t = read();
        l[i].d = read();
    }
    sort(l+1,l+1+m,cmp);

    int t = 0;
    int sum = 0;
    for(int i = 1;i <= n;i ++) fa[i] = i;
    for(int i = 1;i <= m;i ++) {
        int x = find(l[i].f);
        int y = find(l[i].t);
        if(x != y) {
            sum += l[i].d;
            fa[x] = y;
            t ++;
        }
    }
    if(t != n - 1 || sum > c) puts("No");
    else puts("Yes");
}
