#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 8e6 + 10;
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

int f[2][110][110][110];
vector<pii> q[110];

bool check(int i,int j,int k,int t) {
    for(pii p : q[t]) {
        int l = p.first,x = p.second;
        //cout << l << " " << x << endl;
        if(l<=i) if(x!=4) return false; else continue;
        if(l<=j) if(x!=3) return false; else continue;
        if(l<=k) if(x!=2) return false; else continue;
        if(l<=t) if(x!=1) return false; else continue;
    }
    return true;
}

int main() {
    int T = read();
    while(T --) {
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++) q[i].clear();
        for(int i = 1;i <= m;i ++) {
            int l = read(),r = read(),x = read();
            q[r].push_back(make_pair(l,x));
        }

       // cout << check(0,1,2,3) << endl;

        memset(f,0,sizeof f);
        f[0][0][0][0] = 1;
        for(int t = 0,cur = 0;t < n;t ++,cur^=1) {
            for(int k = 0;k <= max(t-1,0);k ++)
                for(int j = 0;j <= max(k-1,0);j ++)
                    for(int i = 0;i <= max(j-1,0);i ++)
                        f[cur^1][i][j][k] = 0;
            for(int k = 0;k <= max(t-1,0);k ++) {
                for(int j = 0;j <= max(k-1,0);j ++) {
                    for(int i = 0;i <= max(j-1,0);i ++) {
                        if(check(i,j,k,t)) {
                   //         printf("(%d,%d,%d,%d) = %d\n",i,j,k,t,f[cur][i][j][k]);
                            (f[cur^1][j][k][t] += f[cur][i][j][k]) %= mod;
                            (f[cur^1][i][k][t] += f[cur][i][j][k]) %= mod;
                            (f[cur^1][i][j][t] += f[cur][i][j][k]) %= mod;
                            (f[cur^1][i][j][k] += f[cur][i][j][k]) %= mod;
                        }
                      // else printf("!(%d,%d,%d,%d) = %d\n",i,j,k,t,f[cur][i][j][k]);
                    }
                }
            }
        }
        int ans = 0;
        for(int k = 0;k <= max(n-1,0);k ++) {
            for(int j = 0;j <= max(k-1,0);j ++) {
                for(int i = 0;i <= max(j-1,0);i ++) {
                    if(check(i,j,k,n)) {
                        (ans += f[n&1][i][j][k]) %= mod;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
/**
2
4 1
1 3 3
*/
