#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<double, double> pdd;
const int SZ = 50100;
const double INF = 1e10 + 10;
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


int n,m,a[17];
double f[17][SZ],C[110][110];
vector<double> g[17];
double G[110][SZ],H[110][17];
int sum[SZ];
int NT[SZ];

// 0:live  1:dead

void print(int x) {
    for(int i = 0;i < n;i ++)
        printf("%d",x>>i&1);
    printf("");
}


void dfs(int d, int S, int nt) {
    if(d == n) {
        for(int i = 0;i <= m;i ++) {
            G[i][S] = g[nt][i];
        }
     /*   for(int i = 0;i <= nt;i ++) {
            for(int j = 0;j <= m;j ++)
                printf("%.10f ",g[i][j]);
            puts("");
        }
        for(int i = 0;i <= m;i ++) {
            print(S); printf("%.10f\n",G[i][S]);
        }*/
        return ;
    }

    for(int i = 0;i <= m;i ++) {
        for(int j = 0;j < a[d+1] && j <= i;j ++)
            g[nt+1][i] += g[nt][i-j] * C[i][j];
    }
    dfs(d+1,S,nt+1); // d is live
    for(int i = 0;i <= m;i ++) {
        g[nt+1][i] = 0;
    }
    dfs(d+1,S^(1<<d),nt);
}

void init() {
    C[0][0] = 1;
    for(int i = 1;i <= 100;i ++) {
        C[i][0] = 1;
        for(int j = 1;j <= i;j ++) {
            C[i][j] = C[i-1][j]+C[i-1][j-1];
        }
    }
}

bool isok(int i,int S) {
    int nS = (1<<n)-S-1;
    return i >= sum[S] && sum[nS] - NT[S] >= i-sum[S];
}

int main() {
    init();
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    for(int S = 0;S < (1<<n);S ++) {
        for(int i = 0;i < n;i ++) {
            if(S>>i&1)
                sum[S] += a[i+1];
        }
    }

    for(int i = 0;i <= n;i ++)
        for(int j = 0;j <= m;j ++)
            g[i].push_back(0);
    g[0][0] = 1;
    dfs(0,0,0);

    for(int j = 0;j < n;j ++) H[0][j] = 1;
    for(int i = 1;i <= m;i ++) {
        H[i][0] = H[i-1][0] / n;
        for(int j = 1;j < n;j ++) {
            H[i][j] = H[i-1][j] / (n-j);
        }
        for(int j = 1;j < n;j ++)
            H[i][j] += H[i][j-1];
    }
    for(int i = 0;i <= m;i ++) {
        for(int j = 0;j <= n;j ++) {
            printf("%.6f ",H[i][j]);
        }
        puts("");
    }

    for(int S = 0; S < (1<<n);S ++) { // S,t: dead   ns,nt: live
        int nt = 0;
        for(int i = 0;i < n;i ++) if(!(S>>i&1)) nt ++;
        NT[S] = nt;
    }

    // 0:live  1:dead
    double ans = 0;
    f[0][0] = 1;
    for(int S = 0; S < (1<<n);S ++) { // 1,t: dead   0,nt: live
        int nt = 0;
        for(int i = 0;i < n;i ++) if(!(S>>i&1)) nt ++;
        int t = n - nt;
        int nS = (1<<n)-S-1;

        for(int i = 0;i < m;i ++) {
            if(f[i][S] < eps) continue;
            if(isok(i,S)) {
                double x = 1;
                for(int j = 0;j < n;j ++) {
                    if(!(S>>j&1)) { // j is alive, make it dead
                        if(isok(i+a[j+1],S^(1<<j))) {
                           // double k = 1.0/nt;
                            double fz = H[a[j+1]-1][t];
                            double fm = nt;
                            double k = fz / fm;
                          //  double k = C[i-sum[S]][a[j+1]-1] / pow(nt,a[j+1]);
                            //f[i+1][S^(1<<j)] += f[i][S] * k;
                            f[i+a[j+1]][S^(1<<j)] += f[i][S] * k;
                            x -= k;
                            printf("trans: [%d][",i); print(S); printf("] * k=%.6f  %.6f/%.6f -> ",k,fz,fm);
                            printf("[%d][",i+a[j+1]); print(S^(1<<j)); printf("]\n");
                        }
                    }
                }
                if(isok(i+1,S)) {
                    if(S == 1 && i == 1) printf("!! %.6f %.6f\n",f[i+1][S],f[i][S]/nt);
                    f[i+1][S] += f[i][S] / nt;

                }
            } else {
                f[i][S] = 0;
            }
        }
        for(int i = 0;i <= m;i ++) {
            printf("f[%d][",i); print(S); printf("] = %.6f, sum: %d, nt:%d\n",f[i][S],sum[S],nt);
        }
        if(m >= sum[S]) {
            print(S);
            printf("%d %.6f %.6f\n",nt,f[m][S],G[m-sum[S]][S]);
            ans += f[m][S] * G[m-sum[S]][S] * t;
        }
    }
    printf("%.10f\n",ans);
}
