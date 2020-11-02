#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
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

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

int n,m,g[222][222],num[222][222],use[2222];

bool isin(int x,int y) { return 1<=x&&x<=n && 1<=y&&y<=m; }

bool dfs(int x,int y) {
    if(x==n&&y==m+1) {
       /* for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                printf("%d ",num[i][j]);
            }
            puts("");
        }*/
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                for(int k = 0;k < 4;k ++) {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(isin(x,y)) {
                        int a = num[x][y];
                        int b = num[i][j];
                        //printf("-%d %d %d\n",a,b,g[a][b]);
                        if(g[a][b]) return false;
                    }
                }
            }
        }
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                printf("%d ",num[i][j]);
            }
            puts("");
        }
        return true;
    }
    if(y == m + 1) x ++,y = 1;
    for(int i = 1;i <= n*m;i ++) {
        if(!use[i]) {
            if(y>1&&g[num[x][y-1]][i]) continue;
            if(x>1&&g[num[x-1][y]][i]) continue;
            use[i] = 1;
            num[x][y] = i;
            if(dfs(x,y+1)) {
                use[i] = 0;
                return true;
            }
            use[i] = 0;
        }
    }
    return false;
}


int main() {
    n = read(),m = read();
    for(int i = 1;i <= n*m;i ++)
        for(int j = 1;j <= n*m;j ++)
            g[i][j] = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            for(int k = 0;k < 4;k ++) {
                int x = i+dx[k];
                int y = j+dy[k];
                if(isin(x,y)) {
                    g[(x-1)*m+y][(i-1)*m+j] = 1;
                }
            }
        }
    }
    dfs(1,1);
}

