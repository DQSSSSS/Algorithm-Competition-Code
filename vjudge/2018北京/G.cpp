#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
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

LL a[111],b[111],s[111];

int main() {
    int n,m;
    while(~scanf("%d%d",&n,&m) && n && m) {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(s,0,sizeof s);
        for(int i = 0;i < n;i ++) a[i] = read(); a[n] = 1;
        reverse(a,a+n+1);
        for(int k = 1;k <= n*m;k ++) {
            s[k] = -k*a[k];
            for(int i = 1;i < k;i ++) s[k] -= s[i] * a[k-i];
        }
        b[0] = 1;
        for(int k = 1;k <= n;k ++) {
            b[k] = 0;
            for(int i = 1;i <= k;i ++) b[k] -= s[i*m] * b[k-i];
            b[k] /= k;
        }
        for(int i = n;i >= 1;i --) {
            printf("%lld%c",b[i],i==1?'\n':' ');
        }
    }
}
