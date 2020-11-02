#include <bits/stdc++.h>
using namespace std;

typedef __int128 LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
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

int fa[SZ];
LL s[5],sz[SZ];

int find(int x) { return x == fa[x] ? x : fa[x]=find(fa[x]); }

int main() {
    int n = read(),m = read();
    s[0] = n;
    s[1] = n;
    s[2] = n;
    s[3] = n;
    LL ans = (LL)n*(n-1)*(n-2)*(n-3)/24;
    for(int i = 1;i <= n;i ++) fa[i] = i,sz[i] = 1;
    for(int i = 1;i <= m;i ++) {
        int x = find(read()),y = find(read());
        printf("%lld\n",(long long)ans);
        if(x != y) {
            LL ai = sz[x],aj = sz[y];
            for(int j = 0;j < 4;j ++) {
                LL t = 1;
                for(int k = 1;k <= j;k ++) t *= ai;
                s[j] -= t;
                t = 1;
                for(int k = 1;k <= j;k ++) t *= aj;
                s[j] -= t;
            }
            ans -= ai*aj*((n-ai-aj)*(n-ai-aj-1)/2 - (s[2]-s[1])/2);
            //cout << ai*aj*((n-ai-aj)*(n-ai-aj-1)/2 - (s[2]-s[1])/2) << endl;
            //ans += (ai+aj)*(1ll*n*n*s[1]-2ll*n*s[2]+s[3]-s[1]*s[2]+s[3])/6;

            fa[x] = y; sz[y] += sz[x];
            for(int j = 0;j < 4;j ++) {
                LL t = 1;
                for(int k = 1;k <= j;k ++) t *= sz[y];
                s[j] += t;
            }
         //   printf("%lld %lld %lld %lld\n",s[0],s[1],s[2],s[3]);
        }
    }
    printf("%lld\n",(long long)ans);
}
