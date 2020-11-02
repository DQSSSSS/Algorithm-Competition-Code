#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

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
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

struct NTT {
    int wn[SZ],wnInv[SZ];
    const int g = 3;
    void init(int n) {
        int d = ksm(g,(mod - 1) / n),t = 1;
        for(int i = 0;i < n;i ++) {
            wn[i] = t;
            wnInv[i] = ksm(wn[i],mod - 2);
            t = 1ll * t * d % mod;
        }
    }   

    void Transform(int *a,int n,const int *wn) {
        for(int i = 0,j = 0;i < n;i ++) {
            if(i < j) swap(a[i],a[j]);
            for(int k = n >> 1;(j ^= k) < k;k >>= 1);
        }
        for(int l = 2;l <= n;l <<= 1) {
            int m = l / 2;
            for(int *p = a;p != a + n;p += l) {
                for(int i = 0;i < m;i ++) {
                    int t = 1ll * wn[n / l * i] * p[m + i] % mod;
                    p[m + i] = (p[i] - t) % mod;
                    (p[i] += t) %= mod;
                }
            }
        }
    }

    void dft(int *a,int n) {
        Transform(a,n,wn);
    }
    void idft(int *a,int n) {
        Transform(a,n,wnInv);
        int t = ksm(n,mod - 2);
        for(int i = 0;i < n;i ++) a[i] = 1ll * a[i] * t % mod;
    }
}ntt;

int c1[SZ],c2[SZ];

int len;

void multiply(int *a,int n,int *b,int m,int *ans) {
    for(int i = 0;i < len;i ++) c1[i] = c2[i] = 0;
    for(int i = 0;i < n;i ++) c1[i] = a[i];
    for(int i = 0;i < m;i ++) c2[i] = b[i];
    ntt.dft(c1,len); ntt.dft(c2,len);
    for(int i = 0;i < len;i ++) c1[i] = 1ll * c1[i] * c2[i] % mod;
   // ntt.idft(c1,len);
    for(int i = 0;i < len;i ++) (ans[i] += c1[i]) %= mod;
    /*for(int i = 0;i < n;i ++) cout << a[i] << " "; puts("");
    for(int i = 0;i < m;i ++) cout << b[i] << " "; puts("");
    for(int i = 0;i < n + m - 1;i ++) cout << ans[i] << " "; puts("");
    puts("--------------");*/
}


char a[SZ],b[SZ],ys[33];

int X[SZ],Y[SZ];
int X1[SZ],Y1[SZ];
int Y0[SZ],Y2[SZ],Y3[SZ],Y4[SZ];
int X0[SZ],X2[SZ],X3[SZ],X4[SZ];
int ans[SZ];
vector<int> g;

int main() {
  //  freopen("73.in","r",stdin);
    scanf("%s%s%s",a,b,ys);
    int n = strlen(b),m = strlen(a);
    for(int i = 0;i < m;i ++) {
        char c = a[i];
        int id = m - i - 1;
       // Y1[m - i - 1] = ys[c - 'a'] - 'a' + 1;
        Y1[id] = ys[c - 'a'] - 'a';
        Y[id] = ys[c - 'a'] - 'a';
    }
    for(int i = 0;i < n;i ++) {
        char c = b[i];
        X1[i] = ys[c - 'a'] - 'a';
        X[i] = ys[c - 'a'] - 'a';
    }
    //for(int i = 0;i < n;i ++) cout << X[i] << " "; puts("");
    //for(int i = 0;i < m;i ++) cout << Y[i] << " "; puts("");
    for(int i = 0;i < m;i ++) {
        Y0[i] = 1;
        Y2[i] = Y1[i] * Y1[i];
        Y3[i] = Y2[i] * Y1[i];
        Y4[i] = Y3[i] * Y1[i];
    }
    for(int i = 0;i < n;i ++) {
        LL x = X1[i];
        X0[i] = x * x * x * x - x * x;
        X1[i] = 2 * x - 4 * x * x * x;
        X2[i] = 6 * x * x - 1;
        X3[i] = -4 * x;
        X4[i] = 1;
    }
    //cout << n << " " << m << endl;
    /*for(int i = 0;i <= n - m;i ++) {
        LL ans = 0;
        for(int j = i;j < i + m;j ++) {
            int x = (X[j] - Y[j - i]);
            ans += x * x * (x * x - 1);
        }
//            ans += Y4[j] + Y3[j] * X3[j] + Y2[j] * X2[j] + Y1[j] * X1[j] + X0[j];
        cout << i << " " << ans << endl;
        int x = (X[i] - Y[i]);
        //cout << x * x * (x * x - 1) * (x * x - 1) << endl;
    }*/
    len = 1; while(len < n + m) len <<= 1;
    ntt.init(len);
    multiply(X0,n,Y0,m,ans);
    multiply(X1,n,Y1,m,ans);
    multiply(X2,n,Y2,m,ans);
    multiply(X3,n,Y3,m,ans);
    multiply(X4,n,Y4,m,ans);
    ntt.idft(ans,len);
   // cout << n << " " << m << " " << len << endl;
    //for(int i = 0;i < n + m - 1;i ++) cout << ans[i] << " "; puts("");
    for(int i = m - 1;i < n;i ++) {
        LL x = ans[i];
       //cout << i << " " << x << endl;
        x %= mod;
        if(x == 0) g.push_back(i - m + 2);
    }
    printf("%lld\n",g.size());
    for(int i = 0;i < g.size();i ++)
        printf("%d%c",g[i],i == g.size() - 1 ? '\n' :' ');
    return 0;
}
/**
aaa
aaa
abcdefghijklmnopqrstuvwxyz
*/
