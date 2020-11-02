#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
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

int f[255][255][255][3];
vector<pii> g;

int main() {
    freopen("khoshaf.in","r",stdin);
/*
    int maxn = 10000;
    for(LL x = 0;x <= maxn;x ++) {
        if(x+x*(x-1)/2 > maxn) break;
        for(LL y = 0;y <= maxn-x;y++) {
            if(x+x*(x-1)/2+y*(y-1)/2 > maxn) break;
            for(LL z = 0;z <= maxn-x-y;z++) {
                if(x+x*(x-1)/2+y*(y-1)/2+z*(z-1)/2 > maxn) break;
            }
        }
    }
*/
    int T = read();
    while(T --) {
        int n = read(),k = read(),l = read(),r = read();
        if(n > 245) { puts("0"); continue; }

        g.clear();
        for(LL x = 0;x <= n;x ++) {
            for(LL y = 0;y <= n-x;y++) {
                LL z = n-x-y;
                if(x+x*(x-1)/2+y*(y-1)/2+z*(z-1)/2 == k)
                    g.push_back(make_pair(x,y));
            }
        }


        LL a[3] = {};
        while(r >= l && (r-l+1) % 3) a[r%3]++,r --;
        for(int i = 0;i < 3;i ++) a[i] += (r-l+1)/3;

        memset(f,0,sizeof f);
        f[0][0][0][0] = 1;
        for(int i = 0;i < n;i ++) {
            for(int j = 0;j <= i;j ++) {
                for(int k = 0;k <= i - j;k ++) {
                    /// f[i][j][k][0] + 0/1/2
                    (f[i+1][j+1][k][0] += f[i][j][k][0]*a[0]%mod) %= mod;
                    (f[i+1][j][k+1][1] += f[i][j][k][0]*a[1]%mod) %= mod;
                    (f[i+1][j][k][2] += f[i][j][k][0]*a[2]%mod) %= mod;

                    /// f[i][j][k][1] + 0/1/2
                    (f[i+1][j][k+1][1] += f[i][j][k][1]*a[0]%mod) %= mod;
                    (f[i+1][j][k][2] += f[i][j][k][1]*a[1]%mod) %= mod;
                    (f[i+1][j+1][k][0] += f[i][j][k][1]*a[2]%mod) %= mod;

                    /// f[i][j][k][2] + 0/1/2
                    (f[i+1][j][k][2] += f[i][j][k][2]*a[0]%mod) %= mod;
                    (f[i+1][j+1][k][0] += f[i][j][k][2]*a[1]%mod) %= mod;
                    (f[i+1][j][k+1][1] += f[i][j][k][2]*a[2]%mod) %= mod;
                }
            }
        }

        LL ans = 0;
       // for(pii x : g) cout << x.first << " " <<x.second << endl;
        for(pii x : g)
            for(int i = 0;i < 3;i ++)
                (ans += f[n][x.first][x.second][i]) %= mod;
        printf("%lld\n",ans);
    }
}
