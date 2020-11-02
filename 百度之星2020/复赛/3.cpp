#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const LL mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int a[SZ],b[SZ];
int mx[SZ],cnt[SZ],mxcnt[SZ],mn[SZ];

void work(int n,int l,int k) {
    for(int i = 1;i <= n;i ++) a[i] = i;
    for(int i = 1;i <= n;i ++) mxcnt[i] = 0;
    int maxn = -1,minn = 1e9;
    do {
        int ans = 0;
        for(int i = 1;i <= n;i ++) cnt[i] = 0;
        for(int i = 1;i <= n-l+1;i ++) {
            for(int j = 0;j < l;j ++) {
                b[j] = a[i+j];
            }
            sort(b,b+l);
            ans += b[l-k];
            cnt[b[l-k]] ++;
        }
        if(ans > maxn) {
            maxn = ans;
            for(int i = 1;i <= n;i ++) mx[i] = a[i];
            for(int i = 1;i <= n;i ++) mxcnt[i] = cnt[i];
        }
        if(ans < minn) {
            minn = ans;
            for(int i = 1;i <= n;i ++) mn[i] = a[i];
        }
    }while(next_permutation(a+1,a+1+n));
    puts("------------------");
    printf("%d %d %d\n",n,l,k);
    printf("max: %d\n",maxn);
    //for(int i = 1;i <= n;i ++) printf("%d ",mx[i]); puts("");
    //for(int i = 1;i <= n;i ++) printf("%d ",mxcnt[i]); puts("");
    printf("min: %d\n",minn);
   // for(int i = 1;i <= n;i ++) printf("%d ",mn[i]); puts("");
}

LL get_ans(int n,int l,int k) {
    sort(a+1,a+1+n);
    int num = n-l+1, s = l - k + 1;
    LL ans = 0;
    //puts("-----");
    for(int i = n-k+1;i >= 1;) {
        LL x = min(num,s);
        ans += x * a[i];
        num -= x;
        int len = k - 1;
       // printf("%lld %d\n",x,a[i]);
        i --;
        for(int j = 1;j <= len;j ++) {
            LL t = min(num,1);
            num -= t;
            ans += t * a[i];
         //   printf("%lld %d\n",t,a[i]);
            i --;
        }
    }
    return ans;
}

int main() {
    int T = read();
    while(T --) {
        int n = read(),l = read(),k = read();
       /* for(int n = 10;n <= 10;n ++) {
            for(int k = 1;k <= n;k ++) {
                for(int l = k;l <= n;l ++) {
                    if(k<=l&&l<=n)
                        work(n,l,k);
                }
            }

        }*/

        for(int i = 1;i <= n;i ++) a[i] = read();
   //     for(int i = 1;i <= n;i ++) a[i] = i;
        LL maxans = get_ans(n,l,k);
        for(int i = 1;i <= n;i ++) a[i] = -a[i];
        LL minans = -get_ans(n,l,l-k+1);
        printf("%lld %lld\n",maxans,minans);
       // work(n,l,k);
    }
}

/*
1
10 4 2
1 2 3 4 5 6 7 8 9 10

1
10 4 2
1 2 3 4 5 6 7 8 9 10
*/
