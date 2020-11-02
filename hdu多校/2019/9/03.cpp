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

int w[44];

int work(int l,int r,LL a[]) {
    int n = r-l+1,tot = 0;
    for(int S = 0;S < (1<<n);S ++) {
        LL sum = 0;
        for(int i = 0;i < n;i ++) {
            if(S >> i & 1) sum += w[i+l];
        }
        a[++ tot] = sum;
    }
    return tot;
}

int g[10][SZ];

void my_sort(LL a[],int n,int k) {
    for(int i = 0;i < 10;i ++) g[i][0] = 0;
    LL B = 1;
    for(int i = 1;i < k;i ++) B *= 10;
    for(int i = 1;i <= n;i ++) {
        int x = a[i] / B % 10;
        g[x][++ g[x][0]] = a[i];
    }
    int tot = 0;
    for(int i = 0;i < 10;i ++) {
        for(int j = 1;j <= g[i][0];j ++) {
            a[++ tot] = g[i][j];
        }
    }
}

LL a[SZ],b[SZ],c[SZ];

int main() {
    //freopen("test.in","r",stdin); freopen("my.out","w",stdout);
    int T = read();
    while(T --) {
        int K = read();
        for(int i = 1;i <= K;i ++) w[i] = read();
        int n = work(1,K/2,a),m = work(K/2+1,K,b);
        LL B = 1,ans = 0;
        for(int k = 1;k <= 10;k ++,B *= 10) {
            my_sort(a,n,k); my_sort(b,m,k);
           // for(int i = 1;i <= n;i ++) printf("%lld ",a[i]); puts("");
           // for(int i = 1;i <= m;i ++) printf("%lld ",b[i]); puts("");
            for(int i = 1;i <= m;i ++) c[i] = b[i] % (B*10);
            int l1 = m+1,r1 = m;
            int l2 = m+1,r2 = m;
            for(int i = 1;i <= n;i ++) {
                int A = a[i] % (B*10);
                while(l1 >= 2 && A + c[l1-1] >= 4 * B) l1 --;
                while(r1 >= 1 && A + c[r1] >= 5 * B) r1 --;
                while(l2 >= 2 && A + c[l2-1] >= 14 * B) l2 --;
                while(r2 >= 1 && A + c[r2] >= 15 * B) r2 --;
                int t = r1 - l1 + 1 + r2 - l2 + 1;
                if(t) {
                 //   printf("%d : [%d,%d] [%d,%d]\n",i,l1,r1,l2,r2);
                    ans += t;
                }
            }
        }
        printf("%lld\n",ans);
    }
}
