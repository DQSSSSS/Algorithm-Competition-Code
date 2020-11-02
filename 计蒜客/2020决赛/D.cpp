#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

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

struct NTTranform {
   	const int g = 3;
	void Transform(int *a,int n,int opt) {
        for(int i = 0,j = 0;i < n;i ++) {
            if(i < j) swap(a[i],a[j]);
            for(int k = n >> 1;(j ^= k) < k;k >>= 1);
        }
        for(int l = 2;l <= n;l *= 2) {
            int m = l / 2;
            int wn = ksm(g,(mod-1)/l);
            if(opt == -1) wn = ksm(wn,mod - 2);
            for(int *p = a;p != a + n;p += l) {
                for(int i = 0,w = 1;i < m;i ++,w=1ll*w*wn%mod) {
                    int t = 1ll * w * p[m + i] % mod;
                    p[m + i] = (p[i] - t + mod) % mod;
					(p[i] += t) %= mod;
                }
            }
        }
	}
	void dft(int *a,const int n) {
        Transform(a,n,1);
	}
	void idft(int *a,const int n) {
        Transform(a,n,-1);
        int t = ksm(n,mod - 2);
        for(int i = 0;i < n;i ++) a[i] = 1ll * a[i] * t % mod;
	}
}fft;

const int T = 300;

struct haha {

    int c[SZ], sum[SZ], sumB[SZ], n, len;
    int t;
    int Binv[SZ];
    int Ainv[SZ];
    vector<pii> Q;

    void maintain() {
        static int C[SZ];
        fft.dft(Ainv, len);
        for(int i = 0;i < len;i ++) C[i] = 1ll * Ainv[i] * Binv[i] % mod;
        fft.idft(C, len);
        for(int i = 0;i < n + n - 1;i ++) (c[i] += C[i]) %= mod;

        sum[0] = c[0];
        for(int i = 1;i < n + n - 1;i ++) sum[i] = (sum[i-1] + c[i]) % mod;

        for(int i = 0;i < len;i ++) Ainv[i] = 0;
    }

    void change(int p,int q) {
        t ++;
        Ainv[p] += q;
        Q.push_back({p, q});
        if(t == T) {
            maintain();
            t = 0; Q.clear();
        }
    }

    int ask(int x) {
        if(x < 0) return 0;
        int ans = sum[x];
        for(pii ppp : Q) {
            int p = ppp.first;
            int q = ppp.second;
            if(p > x) continue;
         //   cout << q << " " << sum[x-p] << endl;
            ans = (ans + 1ll * q * sumB[x-p] % mod) % mod;
        }
        ans += mod; ans %= mod;
       // cout << ans << endl;
        return ans;
    }

    void init(int AA[],int BB[],int nn) {
        n = nn;
        for(int i = 0;i < n;i ++) Binv[i] = BB[i];

        len = 1;
        while(len < n + n) len *= 2;
        fft.dft(Binv, len);
        for(int i = 0;i < n;i ++) {
            Ainv[i] = AA[i];
        }
        sumB[0] = BB[0];
        for(int i = 1;i < 2*n-1;i ++) sumB[i] = (sumB[i-1] + BB[i]) % mod;
        maintain();
    }

    void print() {
        for(int i = 0;i < 2*n-1;i ++) printf("%d ",c[i]); puts("");
        for(int i = 0;i < 2*n-1;i ++) printf("%d ",sum[i]); puts("");
    }

}a;

int A[SZ],B[SZ],n;

int main() {
    n = read() + 1;
    for(int i = 0;i < n;i ++) A[i] = read();
    for(int i = 0;i < n;i ++) B[i] = read();
    a.init(A, B, n);

    int m = read();
    for(int i = 1;i <= m;i ++) {
        int o = read(),l = read(),r = read();
        if(o == 1) {
            printf("%d\n",((a.ask(r)-a.ask(l-1))%mod+mod)%mod);
        }
        else {
            a.change(l,r);
        }
      //  a.print();
    }
}
/*
1
1 1
1 1
100
2 0 1
*/
