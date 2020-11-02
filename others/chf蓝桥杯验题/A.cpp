#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 4e5 + 10;
const int mod = 998244353;
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
    LL ans = 1 % mod;
    while(b) {
        if(b & 1) ans = a * ans % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

int getPhi(int n) {
    int ans = n;
    for(int i = 2;i * i <= n;i ++) {
        if(n % i == 0) {
            ans = ans / i * (i - 1);
            while(n % i == 0) n /= i;
        }
    }
    if(n != 1) ans = ans / n *(n - 1);
    return ans;
}

int getws(int n) {
    int t = 0;
    while(n) n /= 10,t ++;
    return t;
}

bool smaller(char s[],int n) {
    int len1 = strlen(s);
    if(len1 > getws(n)) return false;
    if(len1 < getws(n)) return true;
    int a[22] = {};
    for(int i = 0;i < len1;i ++) a[len1-i-1] = n%10,n/=10;
    for(int i = 0;i < len1;i ++)
        if(a[i] != s[i] - '0')
            return s[i] - '0' < a[i];
    return false;
}

char s[SZ];

int main(){
    int k = read(),p = read();
    scanf("%s",s);
    int phip = getPhi(p);
    cout << phip << endl;
    int mi = 0,len = strlen(s);
    if(smaller(s,phip)) {
        for(int i = 0;i < len;i ++)
            mi = mi * 10ll + s[i] - '0';
        LL ans = 0;
        for(int i = 1;i <= k;i ++)
            ans = (ans + ksm(i,mi,p)) % p;
        cout << ans <<endl;
    }
    else {
        for(int i = 0;i < len;i ++)
            mi = (mi * 10ll + s[i] - '0') % phip;
        mi += phip;
        LL ans = 0;
        for(int i = 1;i <= k;i ++)
            ans = (ans + ksm(i,mi,p)) % p;
        cout << ans <<endl;
    }
}
