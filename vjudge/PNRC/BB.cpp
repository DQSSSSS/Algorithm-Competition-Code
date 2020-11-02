#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

LL f[110][110];
LL g[110][110];
int n,k,m;

bool check(LL mid) {
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++) {
            if(i == j) g[i][j] = 0;
            else g[i][j] = f[i][j] <= mid ? 0 : 1e13;
        }
    for(int k = 1;k <= n;k ++)
        for(int i = 1;i <= n;i ++)
            for(int j = 1;j <= n;j ++) {
                if(i == k || k == j || i == j) continue;
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]+1);
            }
    for(int i = 1;i <= n;i ++)
        for(int j = 1;j <= n;j ++) {
            if(g[i][j] >= k) return false;
        }
    return true;
}

int main() {
    int T = read();
    while(T --) {
        n = read(),k = read(),m = read();
        memset(f,63,sizeof(f));
        for(int i = 1;i <= m;i ++) {
            int x = read()+1,y = read()+1,z = read();
            //g[x].push_back((haha){y,z});
            //g[y].push_back((haha){x,z});
            f[x][y] = f[y][x] = z;
        }
        for(int k = 1;k <= n;k ++) f[k][k] = 0;
        for(int k = 1;k <= n;k ++)
            for(int i = 1;i <= n;i ++)
                for(int j = 1;j <= n;j ++) {
                    //if(i == k || k == j || i == j) continue;
                    f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
                }
       // check(688);
        LL l = 0,r = 1e13;
        while(r - l > 1) {
            LL mid = l + r >> 1;
            if(check(mid)) r = mid;
            else l = mid;
        }
        printf("%lld\n",r);
    }
}
/**
233
10 2 15
0 1 113
1 2 314
2 3 271
3 4 141
4 0 173
5 7 235
7 9 979
9 6 402
6 8 431
8 5 462
0 5 411
1 6 855
2 7 921
3 8 355
4 9 113

*/

