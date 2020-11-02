#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 300010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
const double PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct FFTranform {
    complex<double> omega[SZ],omegaInv[SZ];

    void init(int n) {
        for(int i = 0;i < n;i ++) {
            omega[i] = complex<double>(cos(2 * PI / n * i),sin(2 * PI / n * i));
            omegaInv[i] = conj(omega[i]);
        }
    }

	void Transform(complex<double> *a,int n,complex<double> *omega) {
        int k = 0;
        while((1 << k) < n) k ++;
        for(int i = 0;i < n;i ++) {
        	int t = 0;
        	for(int j = 0;j < k;j ++)
                if(i & (1 << j)) t |= 1 << (k - j - 1);
            if(t > i) swap(a[t],a[i]);
        }
        for(int l = 2;l <= n;l *= 2) {
            int m = l / 2;
            for(complex<double> *p = a;p != a + n;p += l) {
                for(int i = 0;i < m;i ++) {
                    complex<double> t = omega[n / l * i] * p[m + i];
                    p[m + i] = p[i] - t;
					p[i] += t;
                }
            }
        }
	}
	void dft(complex<double> *a,const int n) {
        Transform(a,n,omega);
	}
	void idft(complex<double> *a,const int n) {
        Transform(a,n,omegaInv);
        for(int i = 0;i < n;i ++) a[i] /= n;
	}
}fft;

complex<double> c1[SZ];

void multiply(int *a1,int n1,int *ans) {
	int n = 1;
    while(n < 2 * n1) n *= 2;
    for(int i = 0;i < n;i ++) c1[i] = 0;
    for(int i = 0;i < n1;i ++) c1[i].real(a1[i]);
    fft.init(n); fft.dft(c1,n);
    for(int i = 0;i < n;i ++) c1[i] *= c1[i];
    fft.idft(c1,n);
    for(int i = 0;i < 2 * n1 - 1;i ++) ans[i] = c1[i].real() + 0.5;
}

int a[SZ],ans1[SZ],ans2[SZ],mi[SZ];

LL get_ans(char s[],int n) {
    for(int i = 0;i < n;i ++) a[i] = s[i] == 'a' ? 1 : 0;
    multiply(a,n,ans1);
    for(int i = 0;i < n;i ++) a[i] = s[i] == 'b' ? 1 : 0;
    multiply(a,n,ans2);
	//for(int i = 0;i < 2 * n - 1;i ++) cout << ans1[i] << " "; puts("");
	//for(int i = 0;i < 2 * n - 1;i ++) cout << ans2[i] << " "; puts("");

    //for(int i = 0;i < 2 * n - 1;i ++) ans1[i] += ans2[i];
    //for(int i = 0;i < 2 * n - 1;i ++) cout << i << " "; puts("");
    //for(int i = 0;i < 2 * n - 1;i ++) cout << ans1[i] + ans2[i] << " "; puts("");
    LL ans = 0;
    for(int i = 0;i < 2 * n - 1;i ++) {
    	int x = ans1[i] + ans2[i];
        if(i & 1)
	        (ans += mi[x / 2] - 1) %= mod;
    	else
    		(ans += mi[x / 2 + 1] - 1) %= mod;
    	//cout << mi[x / 2 + !(i & 1)] << " ";
    }
   // puts("");
    //cout << ans << endl;
    return ans;
}

char s2[SZ];
int r[SZ];

LL manacher(char s[],int n) {
    int len = 0;
    s2[++ len] = '@';
    s2[++ len] = '$';
    for(int i = 0;i < n;i ++) {
        s2[++ len]= s[i];
        s2[++ len] = '$';
    }
    s2[len + 1] = '\0';
    int maxr = 0,mid = 0;
    for(int i = 1;i <= len;i ++) {
        int x;
        if(i > maxr) x = 1;
        else x = min(r[mid * 2 - i],maxr - i);
        while(s2[i - x] == s2[i + x]) x ++;
        if(i + x > maxr) maxr = i + x,mid = i;
        r[i] = x;
    }

//	cout << s2 + 1 << endl;
	LL ans = 0;
    //for(int i = 1;i <= len;i ++) cout << s2[i] << " "; puts("");
    //for(int i = 1;i <= len;i ++) cout << r[i] / 2 << " "; puts("");
    for(int i = 1;i <= len;i ++) {
        (ans += r[i] / 2) %= mod;
    }
   // cout << ans << endl;
    return ans;
}

char s[SZ];

int main() {
	mi[0] = 1;
	for(int i = 1;i <= 1e5;i ++) mi[i] = mi[i - 1] * 2 % mod;
    scanf("%s",s);
    int n = strlen(s);
    LL ans = get_ans(s,n);
	(ans -= manacher(s,n)) %= mod;
	ans += mod; ans %= mod;
    printf("%lld\n",ans);
    return 0;
}
