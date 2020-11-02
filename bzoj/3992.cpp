#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1004535809;
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

LL ksm(LL a,LL b,LL mod) {
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
        for(int i = 0;i < n;i ++) {
            wn[i] = ksm(g,(mod - 1) / n * i,mod);
            wnInv[i] = ksm(wn[i],mod - 2,mod);
        }
    }

    void Transform(int *a,int n,int *wn) {
        for(int i = 0,j = 0;i < n;i ++) {
            if(i < j) swap(a[i],a[j]);
        	for(int k = n >> 1;(j ^= k) < k;k >>= 1);
        }
        for(int l = 2;l <= n;l *= 2) {
            int m = l / 2;
            for(int *p = a;p != a + n;p += l) {
                for(int i = 0;i < m;i ++) {
                    LL t = 1ll * wn[n / l * i] * p[m + i] % mod;
                    p[m + i] = (p[i] - t + mod) % mod;
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
    	LL t = ksm(n,mod - 2,mod);
        for(int i = 0;i < n;i ++) a[i] = 1ll * a[i] * t % mod;
    }
}ntt;

int t1[SZ],t2[SZ],len,m;

void multiply(int *a,int *b) {
    //for(int i = 0;i < len;i ++) cout << a[i] << " "; puts("");
    //for(int i = 0;i < len;i ++) cout << b[i] << " "; puts("");
    for(int i = 0;i < len;i ++) t1[i] = a[i],t2[i] = b[i];
    ntt.dft(t1,len); ntt.dft(t2,len);
    for(int i = 0;i < len;i ++) t1[i] = 1ll * t1[i] * t2[i] % mod;
    ntt.idft(t1,len);
    for(int i = 0;i < m - 1;i ++) a[i] = t1[i];
    for(int i = m - 1;i < len;i ++) a[i] = 0,(a[i % (m - 1)] += t1[i]) %= mod;
	//for(int i = 0;i < len;i ++) cout << a[i] << " "; puts("\n");
}

int a[SZ],b[SZ],ans[SZ];

vector<int> getGtmp;
int getG(int p) {
    int x = p - 1;
    for(int i = 2;i <= x;i ++) if(x % i == 0) getGtmp.push_back(i);
    for(int k = 2;;k ++)
		for(int i = 0;i < getGtmp.size();i ++) {
			if(ksm(k,getGtmp[i],p) == 1) {
                if(getGtmp[i] == x)
					return k;
				else break;
			}
		}
}

int ind[SZ],n,res,Snum,g;

int main() {
	n = read(),m = read(),res = read(),Snum = read();
	g = getG(m);
    for(int i = 0,j = 1;i < m - 1;i ++,j = (1ll * j * g) % m) ind[j] = i;
    for(int i = 1;i <= Snum;i ++) {
        int x = read();
        if(x == 0) continue;
        a[ind[x]] = 1;
    }
   // cout << g << endl;
   // for(int i = 1;i < m;i ++) cout << ind[i] << " "; puts("");
	len = 1; while(len < 2 * (m - 1)) len <<= 1;
    ans[0] = 1; ntt.init(len);
    while(n) {
        if(n & 1) multiply(ans,a);
        for(int i = 0;i < len;i ++) b[i] = a[i];
        multiply(a,b);
        n >>= 1;
    }
    //for(int i = 0;i < len;i ++) cout << (ans[i] + mod) % mod << " "; puts("");
   	printf("%d\n",(ans[ind[res]] + mod) % mod);
    return 0;
}
