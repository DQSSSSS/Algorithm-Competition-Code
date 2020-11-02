#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e7 + 10;
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

int pri[SZ];
bool vis[SZ];
vector<int> nodes[SZ],g[100010];
int a[100010];
int minp[SZ];

void shai(int n) {
    int tot = 0;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,minp[i] = i;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                minp[m] = pri[j];
                break;
            }
            else {
                minp[m] = pri[j];
            }
        }
    }
}

bool ban[SZ];
bool use[SZ];
vector<int> ans;

int main() {
    //freopen("G.in","r",stdin);
    //freopen("G.out","w",stdout);
    shai(1e7);
    int n = read(),k = read();
    for(int i = 1;i <= n;i ++) {
        int x = a[i] = read();
      //  printf("%3d",i);
        while(x!=1) {
            int p = minp[x];
            nodes[p].push_back(i);
            g[i].push_back(p);
           // printf("%8d",p);
            while(x % p == 0) x /= p;
        }
       // puts("");
    }

    for(int i = 1;i <= 1e7;i ++) {
        if(ban[i]) continue;
        for(int id : nodes[i]) {
            if(!k) break;
            if(use[id]) continue;
            use[id] = 1;
            k --;
            ans.push_back(id);
        }
        if(!k) break;
        for(int id : nodes[i]) {
            for(int v : g[id]) {
                if(!ban[v]) {
                    ban[v] = 1;
                    for(int x : nodes[v]) use[x] = 1;
                }
            }
        }
    }
    assert(k == 0);

    for(int x : ans) printf("%d ",x); puts("");

   /* int t = 0;
    for(int u : ans) {
        int b = 0;
        for(int v : ans) {
            if(v == u) continue;
            if(__gcd(a[u],a[v]) > 1)
                b ++;
        }
        if(b == ans.size()-1) t ++;
    }
    assert(t == ans.size() || t == 0);*/
}
/**

18 8
11 15 10 6 21 15 10 6 3003 17017 3230 49742 546 41990 17765 570 21945 36465

*/
