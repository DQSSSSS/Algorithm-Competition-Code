#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
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

int a[SZ],b[SZ],p[SZ],pri[SZ],vis[SZ];

int main() {
    int n = read();
    LL t = 0,tot = 0;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,p[i] = tot,b[i] = tot;
        for(int j = 1,m;j <= tot && (m = i * pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                b[m] = p[pri[j]];
                break;
            }
            else {
                b[m] = p[pri[j]];
            }
        }
    }
    for(int i = 2;i <= n;i ++) printf("%d ",b[i]); puts("");
    return 0;
}


