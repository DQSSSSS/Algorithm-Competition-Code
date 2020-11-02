#include<bits/stdc++.h>
using namespace std;

typedef __int128 LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e7 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

template <class T>
void read(T &x) {
	static char ch;static bool neg;
	for(ch=neg=0;ch<'0' || '9'<ch;neg|=ch=='-',ch=getchar());
	for(x=0;'0'<=ch && ch<='9';(x*=10)+=ch-'0',ch=getchar());
	x=neg?-x:x;
}

LL sqrt3(LL n) {
    LL l = 0,r = 1e7+10;
    while(r-l>1) {
        LL mid = (l+r) / 2;
        if(mid * mid * mid <= n) l = mid;
        else r = mid;
    }
    return l;
}

int phi[SZ];
LL sum[SZ];
int pri[SZ / 10];
bool vis[SZ];

void shai(int n) {
    phi[1] = 1;
    int tot = 0;
    for(int i = 2;i <= n;i ++) {
        if(!vis[i]) pri[++ tot] = i,phi[i] = i-1;
        for(int j = 1,m;j <= tot && (m=i*pri[j]) <= n;j ++) {
            vis[m] = 1;
            if(i%pri[j] == 0) {
                phi[m] = phi[i] * pri[j];
                break;
            }
            else {
                phi[m] = phi[i] * phi[pri[j]];
            }
        }
    }
}

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b&1) ans = a * ans % mod;
        a = a *a % mod;
        b >>= 1;
    }
    return ans;
}

LL ni6 = ksm(6,mod-2);
LL ni2 = ksm(2,mod-2);

LL f2(LL n) {
    return n * (n+1) * (2*n+1) / 6;
}

LL f1(LL n) {
    return n * (n+1) / 2;
}

int baoli(int n) {
    int ans = 0;
    for(int i = 1;i <= n;i ++) {
        int x = (int)(pow(i,1.0/3)+1e-6);
        ans += __gcd(x,i);
    }
    return ans;
}

int main() {
    shai(1e7);
    int T; read(T);
    while(T --) {
        LL n; read(n);
        int m = sqrt3(n);
       // cout << m << endl;
        LL ans = 0;
        for(int d = 1;d < m;d ++) {
            LL tmp = 3*d*f2((m-1)/d)+ 3*f1((m-1)/d) + ((m-1)/d);
            ans += phi[d] * tmp;
        }
      //  cout << ans << endl;
        for(int d = 1;d <= m;d ++) {
            if(m % d == 0) {
                ans += phi[d] * (((n/d) - ((LL)m*m*m-1)/d));
            }
        }
        ans %= mod;
        cout << ans << endl;
    }
}
