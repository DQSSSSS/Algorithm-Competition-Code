#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int a[SZ],st[SZ][22];
LL f[20010][110];

void init_st(int n) {
    for(int i = 1;i <= n;i ++) st[i][0] = a[i];
    int x = log2(n);
    for(int j = 1;j <= x;j ++) {
        for(int i = 1;i <= n;i ++) {
            st[i][j] = max(st[i+(1<<(j-1))][j-1],st[i][j-1]);
        }
    }
}

int get_max(int l,int r) {
    int k = log2(r-l+1);
    return max(st[l][k],st[r-(1<<k)+1][k]);
}

int n;

void fz(int k,int L,int R,int l,int r) {
    if(l > r) return ;
    L = max(L,0);
    R = min(R,n);
    LL maxn = 1e18;
    int pos,mid = l + r >> 1;
    for(int i = L;i <= min(mid-1,R);i ++) {
        LL x = f[i][k-1] + (mid-i) * get_max(i+1,mid);
        if(x < maxn) maxn = x,pos = i;
    }
    f[mid][k] = maxn;
    fz(k,L,pos+30,l,mid-1);
    fz(k,pos-30,R,mid+1,r);
}

int main() {
    n = read();
    int k = read();
    for(int i = 1;i <= n;i ++) a[i] = read();
    init_st(n);

   // for(int j = 1;j <= n;j ++) printf("%3d",j); puts("");

    for(int i = 1,maxn = 0,pos;i <= n;i ++) {
        if(a[i] > maxn) maxn = a[i],pos = i;
        f[i][1] = 1ll * maxn * i;
  //      printf("%3d",pos);
    }
  //  puts("");

    for(int i = 2;i <= k;i ++) {
        fz(i,0,n,1,n);
       /* for(int j = 1;j <= n;j ++) {
            f[j][i] = 1e18;
            int pos;
            for(int l = 0;l < j;l ++) {
                if(f[j][i] >= f[l][i-1] + (j-l) * get_max(l+1,j))
                    f[j][i] = f[l][i-1] + (j-l) * get_max(l+1,j),pos = l;
            }
           // printf("%7lld",f[j][i]);
            printf("%3d",pos);
        }
        puts("");*/
    }
    printf("%lld\n",f[n][k]);
}
/**
29 10
7515 18432 14593 19836 6558 17259 9423 7329 12122 2100 14222 9762 6799 4817 2481 18743 6947 10300 1839 19548 17728 370 16931 13874 1617 950 14988 13597 8360
*/
