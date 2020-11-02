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

int main() {
    int T = read();
    while(T --) {
        int n = read();
        lshx[0] = 0;
        lshy[0] = 0;
        for(int i = 1;i <= n;i ++) {
            a[i].x1 = read(); a[i].y1 = read();
            a[i].x2 = read(); a[i].y2 = read();
            lshx[++ lshx[0]] = a[i].x1-1;
            lshx[++ lshx[0]] = a[i].x1;
            lshx[++ lshx[0]] = a[i].x2;
            lshx[++ lshx[0]] = a[i].x2+1;
            lshy[++ lshy[0]] = a[i].y1-1;
            lshy[++ lshy[0]] = a[i].y1;
            lshy[++ lshy[0]] = a[i].y2;
            lshy[++ lshy[0]] = a[i].y2+1;
        }
        int sx = read(),sy = read();
        int ex = read(),ey = read();
        lshx[++ lshx[0]] = sx;
        sort(lshx+1,lshx+1+lshx[0]); lshx[0] = unique(lshx+1,lshx+1+lshx[0])-lshx-1;
        sort(lshy+1,lshy+1+lshy[0]); lshy[0] = unique(lshy+1,lshy+1+lshy[0])-lshy-1;
        for(int i = 1;i <= lshx[0];i ++) {
            for(int j = 1;j <= lshy[0];j ++) {
                sum[i][j] = 0;
            }
        }
        for(int i = 1;i <= n;i ++) {
            a[i].x1 = lower_bound(lshx+1,lshx+1+lshx[0],a[i].x1)-lshx;
            a[i].x2 = lower_bound(lshx+1,lshx+1+lshx[0],a[i].x2)-lshx;
            a[i].y1 = lower_bound(lshy+1,lshy+1+lshy[0],a[i].y1)-lshy;
            a[i].y2 = lower_bound(lshy+1,lshy+1+lshy[0],a[i].y2)-lshy;
            sum[a[i].x1][a[i].y1] ++;
            sum[a[i].x1][a[i].y2+1] --;
            sum[a[i].x2+1][a[i].y1] --;
            sum[a[i].x2+1][a[i].y2+1] ++;
        }
        for(int i = 1;i <= lshx[0];i ++) {
            for(int j = 1;j <= lshy[0];j ++) {
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
            }
        }

    }
}

