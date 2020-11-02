#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 6e6 + 10;
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

int tree[SZ],n,k,f[SZ];
LL S[SZ],lsh[SZ];

void add(int x,int d) {
    x = lsh[0] - x + 1;
    for(int i = x;i <= lsh[0];i += i&-i) tree[i] = max(tree[i],d);
}

int ask(int x) {
    x = lsh[0] - x + 1;
    int ans = -INF;
    for(int i = x;i > 0;i -= i&-i) ans = max(tree[i],ans);
    return ans;
}

int check(LL mid) {
    int ans = 0;
    for(int i = 1;i <= lsh[0];i ++) tree[i] = -INF;
    add(lower_bound(lsh+1,lsh+1+lsh[0],0)-lsh,0);
    for(int i = 1;i <= n;i ++) {
     //   for(int j = 1;j <= lsh[0];j ++) printf("%d ",ask(j)); puts("");
        int id = lower_bound(lsh+1,lsh+1+lsh[0],S[i]-mid) - lsh;
        f[i] = ask(id) + 1;
    //    printf("%d %d %d\n",i,f[i],id);
        int p = lower_bound(lsh+1,lsh+1+lsh[0],S[i]) - lsh;
        add(p,f[i]);
        ans = max(ans,f[i]);

    }
   /* for(int i = 1;i <= n;i ++) {
        f[i] = 0;
        for(int j = 0;j < i;j ++) {
            if(S[i] - S[j] <= mid)
                f[i] = max(f[i],f[j]+1);
        }
        ans = max(ans,f[i]);
    }*/
    return ans;
}

int a[SZ];

int main() {
    int T = read();
    while(T --) {
        n = read(),k = read();
        lsh[n+1] = 0;
        lsh[n+2] = 1e15;
        for(int i = 1;i <= n;i ++) {
            a[i] = read();
            S[i] = S[i-1] + a[i];
            lsh[i] = S[i];
        }
        sort(lsh+1,lsh+1+n+2);
        lsh[0] = unique(lsh+1,lsh+1+n+2) - lsh - 1;
     //   for(int i = 1;i <= lsh[0];i ++) printf("%lld ",lsh[i]); puts("");
     //   printf("%d\n",check(3));
        LL L = -1,R = 4e14;
        while(R - L > 1) {
            LL mid = L + R >> 1;
            if(check(mid-2e14) < k) L = mid;
            else R = mid;
        }
        printf("%lld\n",(LL)(R-2e14));
    }
}
/***
2
5 4
-1 -1 -1 -1 6
*/
