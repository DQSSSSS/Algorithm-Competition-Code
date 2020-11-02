#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 200010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int a[110][110];
int use[110][110];
int vis[110][110],n,m;

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

bool isin(int x,int y) {
    return x>= 1 && x <= n && y >= 1 && y <= m;
}

bool find(int x,int y) {
    int val = a[x][y],sum = 0,t = 0;
    for(int k = 0;k < 4;k ++) {
        int i = x,j = y;
        while(isin(i+dx[k],j+dy[k])) {
            i += dx[k];
            j += dy[k];
            if(!use[i][j]) {
                sum += a[i][j];
                t ++;
                break;
            }
        }
    }
    return val * t < sum;
}

int work() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            a[i][j] = read();
            use[i][j] = 0;
        }
    }
    LL ans = 0;
    while(1) {
        bool flag = 0;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                if(!use[i][j]) {
                    if(find(i,j)) {
                        flag = 1;
                        vis[i][j] = 1;
                    }
                }
            }
        }
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                if(!use[i][j]) {
                    ans += a[i][j];
                }
                if(vis[i][j]) {
                    vis[i][j] = 0;
                    use[i][j] = 1;
                }
            }
        }
        if(!flag) break;
    }
    printf("%lld\n",ans);
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        printf("Case #%d: ",++ cc);
        work();
    }
}
