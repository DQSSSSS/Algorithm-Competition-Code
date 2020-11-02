#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 2e6 + 10;
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

int dist[11][11];

int askdist(int x1,int y1,int x2,int y2) {
    int dx = abs(x1-x2);
    int dy = abs(y1-y2);
    if(dx>dy) swap(dx,dy);
    if(dx + dy < 6) return dist[dx][dy];
    if(dx >= 2) return dx+dy;
    int d = dx+dy,dd = dx+dy;
    dd -= 6; dd %= 4;
   // cout << dx << " " << dy << endl;
    if(dx == 0) {
        if(dd == 0) return d+2;
        if(dd == 1) return d+2;
        if(dd == 2) return d;
        if(dd == 3) return d+2;
    }
    else if(dx == 1) {
        if(dd == 0) return d+2;
        if(dd == 1) return d+2;
        if(dd == 2) return d+2;
        if(dd == 3) return d;
    }
}

int X[22],Y[22];
int f[100010][22];

int main() {
dist[0][0]=0;
dist[0][1]=3;
dist[0][2]=4;
dist[0][3]=5;
dist[0][4]=4;
dist[0][5]=7;
dist[1][1]=6;
dist[1][2]=5;
dist[1][3]=6;
dist[1][4]=5;
dist[2][2]=4;
dist[2][3]=5;

    /*for(int i = 0;i <= 30;i ++) {
        for(int j = 0;j <= 30;j ++) {
            printf("%3d",askdist(0,0,i,j));
        }
        puts("");
    }*/
    int T = read();
    while(T --) {
        int n = read();
        for(int i = 0;i < n;i ++) {
            X[i] = read();
            Y[i] = read();
        }
        for(int i = 0;i < (1<<n);i ++)
            for(int j = 0;j < n;j ++)
                f[i][j] = 1e9;
        for(int i = 0;i < n;i ++)
            f[1<<i][i] = askdist(0,0,X[i],Y[i]);

        for(int S = 0;S < (1<<n);S ++) {
            for(int i = 0;i < n;i ++) {
                if(S>>i&1) {
                    for(int j = 0;j < n;j ++) {
                        if((S>>j&1)==0) {
                            f[S^(1<<j)][j] = min(f[S^(1<<j)][j],f[S][i] + askdist(X[i],Y[i],X[j],Y[j]));
                        }
                    }
                }
            }
        }
        int ans = 1e9;
        for(int i = 0;i < n;i ++) {
            ans = min(ans,f[(1<<n)-1][i]);
        }
        printf("%d\n",ans);
    }
}
