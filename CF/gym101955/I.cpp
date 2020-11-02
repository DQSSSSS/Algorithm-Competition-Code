#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<int,LL> pil;
typedef pair<LL,LL> pll;
const int SZ = 1e5 + 10;
const LL INF = 1e18;
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

LL f[2050][2050],g[2050][2050],h[2050][2050];
int N;

void FWT_xor(LL *a,int opt) {
    for(int i=1;i<N;i<<=1)
        for(int p=i<<1,j=0;j<N;j+=p)
            for(int k=0;k<i;++k) {
                LL X=a[j+k],Y=a[i+j+k];
                a[j+k]=(X+Y);a[i+j+k]=(X-Y);
                if(opt==-1) {
                    a[j+k]=a[j+k] / 2;
                    a[i+j+k]=a[i+j+k] / 2;
                }
            }
}

LL a[2050],b[2050],c[2050],ans[2050],ans2[2050];
LL bl[2050];

int A,B,C,D,E,F;

void getbl(int d) {
    for(int i = 0;i < N;i ++) bl[i] = 0;
    for(int i = 0;i < A;i ++) {
        for(int j = 0;j < B;j ++) {
            for(int k = 0;k < C;k ++) {
                for(int a = 0;a < D;a ++) {
                    for(int b = 0;b < E;b ++) {
                        for(int c = 0;c < F;c ++) {
                            int x = abs(i-a);
                            int y = abs(j-b);
                            int z = abs(k-c);
                            if(max(max(x,y),z) == d) {
                                bl[i^j^k^a^b^c] ++;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int T = read(),cc = 0;
    while(T --) {
        A = read()+1,B = read()+1,C = read()+1;
        D = read()+1,E = read()+1,F = read()+1;
        N = 8;
        for(int i = 0;i < N;i ++) {
            for(int j = 0;j < N;j ++) {
                f[i][j] = g[i][j] = h[i][j] = 0;
            }
            ans2[i] = 0;
        }

        for(int i = 0;i < A;i ++) {
            for(int j = 0;j < D;j ++) {
                f[i^j][abs(i-j)] ++;
            }
        }
        for(int i = 0;i < B;i ++) {
            for(int j = 0;j < E;j ++) {
                g[i^j][abs(i-j)] ++;
            }
        }
        for(int i = 0;i < C;i ++) {
            for(int j = 0;j < F;j ++) {
                h[i^j][abs(i-j)] ++;
            }
        }

        for(int i = 0;i < N;i ++) {
            for(int j = 1;j < N;j ++) {
                f[i][j] += f[i][j-1];
                g[i][j] += g[i][j-1];
                h[i][j] += h[i][j-1];
            }
        }

        ULL sum = 0;
        for(int d = 0;d <= 5;d ++) {
            for(int i = 0;i < N;i ++) {
                a[i] = f[i][d];
                b[i] = g[i][d];
                c[i] = h[i][d];
            }
            printf("%d\n",d);
            for(int i = 0;i < N;i ++) printf("%lld ",a[i]); puts("");
            for(int i = 0;i < N;i ++) a[i] = 0;
            for(int k = 0;k < N;k ++) {
                for(int i = 0;i < A;i ++) {
                    int j = i^k;
                    if(j < D && abs(i-j) <= d) a[k] ++;
                }
            }
            for(int i = 0;i < N;i ++) printf("%lld ",a[i]); puts("");
            for(int i = 0;i < N;i ++) printf("%lld ",b[i]); puts("");
            for(int i = 0;i < N;i ++) printf("%lld ",c[i]); puts("");
            FWT_xor(a,1);
            FWT_xor(b,1);
            FWT_xor(c,1);
            for(int i = 0;i < N;i ++) ans[i] = a[i] * b[i] * c[i];
            FWT_xor(ans,-1);

            getbl(d);
            for(int i = 0;i < N;i ++) printf("%lld ",ans[i]); puts("");
            for(int i = 0;i < N;i ++) printf("%lld ",ans2[i]); puts("");
            for(int i = 0;i < N;i ++) printf("%lld ",ans[i]-ans2[i]); puts("");
            for(int i = 0;i < N;i ++) printf("%lld ",bl[i]); puts("");

            for(int i = 0;i < N;i ++) {
                ans[i] -= ans2[i];
                sum += (ULL)ans[i] * (i^d);
                ans2[i] = ans[i];
            }
        }
        printf("Case #%d: %llu\n",++ cc,sum);
    }
}
