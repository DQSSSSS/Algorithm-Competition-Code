#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 998244353;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

const int MAXN = 5005;
LL sum[5010][5010];
LL b[5010];

struct haha {
    int x1,x2,y1,y2;
    LL ans1,ans2;
}a[SZ];

void add(int x,int y,int d) { sum[x][y] += d; }
LL ask(int x1,int y1,int x2,int y2) {
    if(x1<=x2&&y1<=y2)
        return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
    return 0;
}

int main() {
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 1;i <= MAXN;i ++)
            for(int j = 1;j <= MAXN;j ++)
                sum[i][j] = 0;
        for(int i = 1;i <= n;i ++) {
            a[i].x1 = read()+1; a[i].y1 = read()+1;
            a[i].x2 = read(); a[i].y2 = read();
            a[i].ans1 = 0;
            a[i].ans2 = 0;
            add(a[i].x1,a[i].y1,1);
            add(a[i].x1,a[i].y2+1,-1);
            add(a[i].x2+1,a[i].y1,-1);
            add(a[i].x2+1,a[i].y2+1,1);
        }
        for(int i = 1;i <= MAXN;i ++)
            for(int j = 1;j <= MAXN;j ++)
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        for(int i = 1;i <= MAXN;i ++)
            for(int j = 1;j <= MAXN;j ++)
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

        for(int i = 1;i <= n;i ++) {
            a[i].ans2 = ask(a[i].x1,a[i].y1,a[i].x2,a[i].y2);
            a[i].ans2 -= (a[i].x2-a[i].x1+1) * (a[i].y2-a[i].y1+1);
        }

        for(int i = 1;i <= MAXN;i ++) b[i] = 0;
        for(int i = 1;i <= n;i ++) b[a[i].x2] ++;
        for(int i = 1;i <= MAXN;i ++) b[i] += b[i-1];
        for(int i = 1;i <= n;i ++) a[i].ans1 += b[a[i].x1-1];

        for(int i = 1;i <= MAXN;i ++) b[i] = 0;
        for(int i = 1;i <= n;i ++) b[a[i].x1] ++;
        for(int i = MAXN-1;i >= 1;i --) b[i] += b[i+1];
        for(int i = 1;i <= n;i ++) a[i].ans1 += b[a[i].x2+1];

        for(int i = 1;i <= MAXN;i ++) b[i] = 0;
        for(int i = 1;i <= n;i ++) b[a[i].y2] ++;
        for(int i = 1;i <= MAXN;i ++) b[i] += b[i-1];
        for(int i = 1;i <= n;i ++) a[i].ans1 += b[a[i].y1-1];

        for(int i = 1;i <= MAXN;i ++) b[i] = 0;
        for(int i = 1;i <= n;i ++) b[a[i].y1] ++;
        for(int i = MAXN-1;i >= 1;i --) b[i] += b[i+1];
        for(int i = 1;i <= n;i ++) a[i].ans1 += b[a[i].y2+1];


        for(int i = 1;i <= MAXN;i ++)
            for(int j = 1;j <= MAXN;j ++)
                sum[i][j] = 0;
        for(int i = 1;i <= n;i ++) add(a[i].x2,a[i].y2,1);
        for(int i = 1;i <= MAXN;i ++)
            for(int j = 1;j <= MAXN;j ++)
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        for(int i = 1;i <= n;i ++) a[i].ans1 -= ask(1,1,a[i].x1-1,a[i].y1-1);

        for(int i = 1;i <= MAXN;i ++)
            for(int j = 1;j <= MAXN;j ++)
                sum[i][j] = 0;
        for(int i = 1;i <= n;i ++) add(a[i].x2,a[i].y1,1);
        for(int i = 1;i <= MAXN;i ++)
            for(int j = 1;j <= MAXN;j ++)
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        for(int i = 1;i <= n;i ++) a[i].ans1 -= ask(1,a[i].y2+1,a[i].x1-1,MAXN);


        for(int i = 1;i <= MAXN;i ++)
            for(int j = 1;j <= MAXN;j ++)
                sum[i][j] = 0;
        for(int i = 1;i <= n;i ++) add(a[i].x1,a[i].y2,1);
        for(int i = 1;i <= MAXN;i ++)
            for(int j = 1;j <= MAXN;j ++)
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        for(int i = 1;i <= n;i ++) a[i].ans1 -= ask(a[i].x2+1,1,MAXN,a[i].y1-1);

        for(int i = 1;i <= MAXN;i ++)
            for(int j = 1;j <= MAXN;j ++)
                sum[i][j] = 0;
        for(int i = 1;i <= n;i ++) add(a[i].x1,a[i].y1,1);
        for(int i = 1;i <= MAXN;i ++)
            for(int j = 1;j <= MAXN;j ++)
                sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        for(int i = 1;i <= n;i ++) a[i].ans1 -= ask(a[i].x2+1,a[i].y2+1,MAXN,MAXN);

        for(int i = 1;i <= n;i ++)
            printf("%lld %lld\n",n-a[i].ans1-1,a[i].ans2);
    }
}
