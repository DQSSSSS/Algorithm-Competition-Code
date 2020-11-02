#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 800100;
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

const int m = 500;

long double f[8][510][m+10];
int p[8][8];
long double g[8][510][m+10],gl[8][510];

int main() {
    int n = read();
    for(int i = 1;i <= 6;i ++)
        for(int j = 1;j <= 6;j ++) {
            int x,y;
            scanf("%d.%d",&x,&y);
            p[i][j] = x*100+y;
        }
    for(int i = 2;i <= 7;i ++)
        for(int j = 1;j <= 6;j ++)
            f[j][i][1] = p[j][i-1] / 100.0;

    for(int i = 1;i <= 6;i ++)
        for(int j = 1;j < m;j ++)
            for(int k = 1;k <= n;k ++) {
                for(int l = 1;l <= 6;l ++) {
                    int nx = (k + l - 1) % n + 1;
                    f[i][nx][j+1] += f[i][k][j] * p[i][l] / 100.0;
                }
            }

    for(int j = 1;j <= 6;j ++)
        for(int i = 1;i <= n;i ++)
            g[j][i][0] = 1;

    for(int j = 1;j <= 6;j ++)
        for(int i = 1;i <= m;i ++)
            for(int k = 1;k <= n;k ++)
                g[j][k][i] = g[j][k][i - 1] * (1-f[j][k][i]);

    for(int i = 1;i <= 6;i ++)
        for(int j = 1;j <= n;j ++) {
            for(int k = 1;k <= m;k ++) {
                long double p = g[i][j][k-1] * f[i][j][k];
                for(int l = 1;l <= 6;l ++) {
                    if(l < i) p *= g[l][j][k];
                    else if(l > i) p *= g[l][j][k-1];
                }
                gl[i][j] += p;
            }
        }

    for(int i = 1;i <= 6;i ++) {
        long double ans = 0;
        for(int j = 1;j <= n;j ++) {
            ans += gl[i][j];
        }
        printf("%.3f\n",(double)ans);
    }
    return 0;
}
/**
500
1.00 0.00 0.00 0.00 0.00 0.00
0.00 1.00 0.00 0.00 0.00 0.00
0.00 0.00 1.00 0.00 0.00 0.00
0.00 0.00 0.00 1.00 0.00 0.00
0.00 0.00 0.00 0.00 1.00 0.00
0.00 0.00 0.00 0.00 0.00 1.00
100.000
50.000
100.000
67.000
84.000
99.000

500
0.17 0.28 0.15 0.00 0.29 0.10
0.25 0.19 0.20 0.20 0.02 0.14
0.20 0.07 0.15 0.23 0.24 0.11
0.13 0.17 0.42 0.02 0.01 0.25
0.28 0.25 0.07 0.05 0.06 0.29
0.18 0.10 0.27 0.14 0.26 0.05
39.725
58.297
130.899
98.320
80.041
92.717
*/
