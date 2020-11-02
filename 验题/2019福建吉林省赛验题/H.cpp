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

int a[SZ],pri[SZ];
bool vis[1000010];
int minpri[1000010];

void shai(int n) {
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ pri[0]] = i,minpri[i] = i;
        for(int j = 1,m;j <= pri[0] && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i % pri[j] == 0) {
                minpri[m] = minpri[i];
                break;
            }
            else minpri[m] = pri[j];
        }
    }
}

int id[1000010],tot;
vector<int> mp[SZ];
stack<int> Stk;

int main() {
    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);
    shai(1e6);
    int T = read();
    while(T --) {

        while(Stk.size()) id[Stk.top()] = 0,Stk.pop();
        for(int i = 1;i <= tot;i ++) mp[i].clear();
        tot = 0;

        int n = read();
        for(int i = 1;i <= n;i ++) {
            int x = read();
            vector<int> pri;
            while(x != 1) {
                int p = minpri[x];
                pri.push_back(p);
                while(x % p == 0) x /= p;
            }
            int S = 1 << int(pri.size());
            for(int j = 0;j < S;j ++) {
                int ans = 1;
                for(int k = 0;k < pri.size();k ++) {
                    if(j >> k & 1) ans *= pri[k];
                }
                if(!id[ans]) {
                    assert(tot < SZ);
                    id[ans] = ++ tot,Stk.push(ans);
                }
                mp[id[ans]].push_back(i);
            }
        }
        int m = read();
        while(m --) {
            int l = read(),r = read(),x = read();
            int ans = 0;
            vector<int> pri;
            while(x != 1) {
                int p = minpri[x];
                pri.push_back(p);
                while(x % p == 0) x /= p;
            }
            int S = 1 << int(pri.size());
            for(int j = 0;j < S;j ++) {
                int t = 1,mu = 1;
                for(int k = 0;k < pri.size();k ++) {
                    if(j >> k & 1) t *= pri[k],mu = -mu;
                }
                if(!id[t]) continue;
                int x = id[t];
                int R = lower_bound(mp[x].begin(),mp[x].end(),r) - mp[x].begin();
                if(R == mp[x].size() || mp[x][R] > r) R --;

                int L = lower_bound(mp[x].begin(),mp[x].end(),l) - mp[x].begin();
                ans += mu * max(0,R-L+1);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

/**
2
5
2 4 1 3 6
2
1 5 2
2 3 2
3
3 3 3
2
1 2 6
1 2 5
*/
