#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2e5 + 10;
const int mod = 100000007;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

int F(int a,int b,int k) {
    if(k == -1) return 0;
    int x = a>>k&1;
    int y = b>>k&1;
    if(x == y) return 1+F(a,b,k-1);
    return 0;
}

int m,n,L[SZ],R[SZ],f[2][22][22];
int st[22][SZ],lg2[SZ];

int ask(int l,int r) {
    return F(l-1,r,m-1);
    if(l == r + 1) return m-1;
    int k = lg2[r-l+1];
    return min(st[k][l],st[k][r-(1<<k)+1]);
}

LL work() {
    memset(f,0,sizeof f);
    for(int k = L[1];k <= R[1];k ++) {
        int x = F(k,R[1],m-1);
        int y = F(k,R[1]+1,m-1);
        //cout << k << " " << x << " " <<y << endl;
        (f[1][x][y] += k) %= mod;
    }
/*    for(int a = 0;a <= m;a ++) {
        for(int b = 0;b <= m;b ++) {
            printf("%d ",f[1][a][b]);
        }
        puts("");
    }*/
    for(int i = 2;i <= n;i ++) {
        int cur = i & 1,pr = cur ^ 1;
        memset(f[cur],0,sizeof f[cur]);
        for(int k = L[i];k <= R[i];k ++) {
            int x = ask(k+1,R[i]);
            int y = ask(k+1,R[i]+1);
            int u = ask(L[i],k);
            int v = ask(L[i]+1,k);
            x = F(k,R[i],m-1), y = F(k,R[i]+1,m-1);
            u = F(k,L[i]-1,m-1), v = F(k,L[i],m-1);
            for(int a = 0;a <= m;a ++) {
                for(int b = 0;b <= m;b ++) {
                    if(!(u <= a && v >= b)) continue;
                    (f[cur][x][y] += 1ll * k * f[pr][a][b] % mod) %= mod;
                }
            }
        }
        /*for(int a = 0;a <= m;a ++) {
            for(int b = 0;b <= m;b ++) {
                printf("%d ",f[pr][a][b]);
            }
            puts("");
        }*/
    }
    int ans = 0;
    for(int a = 0;a <= m;a ++) {
        for(int b = 0;b <= m;b ++) {
            (ans += f[n&1][a][b]) %= mod;
        }
    }
    /*
    for(int i = 1;i <= n;i ++) {
        for(int j = 0;j <= m;j ++) printf("%d ",f[i][j]);
        puts("");
    }*/
    return ans;
}

int main() {
    for(int i = 1;i <= (1<<17);i ++) lg2[i] = log2(i);
    int T = read();
    while(T --) {
        m = read(),n = read();
        for(int i = 1;i <= n;i ++) L[i] = read(),R[i] = read();
        printf("%d\n",work());
    }
}

/*
1
2 2
0 1
2 3
*/
