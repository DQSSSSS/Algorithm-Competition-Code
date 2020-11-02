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
    /// 要完备匹配，即nl <= nr
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

int mz[SZ];

int main() {
/*
    freopen("80.in","w",stdout);
    int B = 400;
    cout << B << " " << B << " " << B*B << endl;
    for(int i = 1;i <= B;i ++)
        for(int j = 1;j <= B;j ++)
            cout << i << " " << j << " " << i*j << endl;
*/
    freopen("80.in","r",stdin);
    int m,flag = 0;
    scanf("%d%d%d",&KM::nl,&KM::nr,&m);
    if(KM::nl > KM::nr) swap(KM::nl,KM::nr),flag = 1;
    for(int i = 1;i <= m;i ++) {
        int x = read(),y = read(),z = read();
        if(!flag) KM::f[x][y] = z;
        else KM::f[y][x] = z;
    }
    LL ans = KM::KM();
    printf("%lld\n",ans);
    if(flag) {
        for(int i = 1;i <= KM::nr;i ++)
            printf("%d ",KM::f[KM::mat[i]][i] ? KM::mat[i] : 0);

    }
    else {
        for(int i = 1;i <= KM::nr;i ++) if(KM::f[KM::mat[i]][i]) mz[KM::mat[i]] = i;
        //for(int i = 1;i <= KM::nr;i ++) cout << KM::mat[i] << " "; puts("");
        for(int i = 1;i <= KM::nl;i ++) printf("%d ",mz[i]);
    }
    return 0;
}
