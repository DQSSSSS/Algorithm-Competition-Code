#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 510;
const LL INF = 1e18 + 10;
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

namespace KM {
    int nl,nr,mat[SZ];  /// 左右部点个数、匹配情况
    LL f[SZ][SZ];   /// 邻接矩阵
    LL lv[SZ],rv[SZ],rst[SZ];
    bool visl[SZ],visr[SZ];

    bool dfs(int u) {
        visl[u] = 1;
        for(int v = 1;v <= nr;v ++) {
            if(visr[v]) continue;
            LL d = lv[u] + rv[v] - f[u][v];
            if(d == 0) {
                visr[v] = 1;
                if(!mat[v] || dfs(mat[v]))
                    { mat[v] = u; return true; }
            }
            else
                rst[v] = min(rst[v],d);
        }
        return false;
    }
    LL KM() {
        memset(mat,0,sizeof(mat));
        memset(rv,0,sizeof(rv));
        for(int i = 1;i <= nl;i ++) {
            lv[i] = f[i][1];
            for(int j = 2;j <= nr;j ++)
                lv[i] = max(lv[i],f[i][j]);
        }
        for(int x = 1;x <= nl;x ++) {
            fill(rst + 1,rst + 1 + nr,INF);
            while(233) {
                for(int i = 1;i <= nl;i ++) visl[i] = 0;
                for(int i = 1;i <= nr;i ++) visr[i] = 0;
                if(dfs(x)) break;
                LL d = INF;
                for(int i = 1;i <= nr;i ++)
                    if(!visr[i]) d = min(d,rst[i]);
                for(int i = 1;i <= nl;i ++)
                    if(visl[i]) lv[i] -= d;
                for(int i = 1;i <= nr;i ++)
                    if(visr[i]) rv[i] += d;
                    else rst[i] -= d;
            }
        }
        LL ans = 0;
        for(int i = 1;i <= nr;i ++)
            ans += f[mat[i]][i];
        return ans;
    }
}

LL a[SZ],b[SZ],k[SZ];

int main() {
    int n;
    while(~scanf("%d",&n)) {
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= n;j ++) {
                KM::f[i][j] = read();
            }
        }
        KM::nl = KM::nr = n;
        cout << KM::KM() << endl;
    }
    return 0;
}

