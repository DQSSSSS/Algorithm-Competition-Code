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

char s[55];
int n,m;
LL f[55][55];
LL g[55][55][55];

bool isequ(int len,int p1,int p2) {
    string s1,s2;
    for(int i = 1;i <= len;i ++) {
        if(i==p1) {
            if(s[i] == '0') s1 += '1';
            else s1 += '0';
        }
        else s1 += s[i];
    }
    for(int i = n-len+1;i <= n;i ++) {
        if(i==p2) {
            if(s[i] == '0') s2 += '1';
            else s2 += '0';
        }
        else s2 += s[i];
    }
    return s1 == s2;
}

int main() {
    int T = read();
    while(T --) {
        n = read(),m = read();
        scanf("%s",s+1);
        for(int j = 0;j <= n;j ++) {
            for(int k = 1;k < n;k ++) {
                for(int l = 0;l <= n;l ++) {
                    if(isequ(k,j,l)) {
                        g[j][k][l] = 1;
                    }
                    else {
                        g[j][k][l] = 0;
                    }
                }
            }
        }
        for(int i = 1;i <= m;i ++) {
            for(int j = 0;j <= n;j ++) {
                if(i-n < 0) {
                    f[i][j] = 0;
                    continue;
                }
                LL ans = 1ll<<(i-n);
                for(int k = 1;k < i;k ++) {
                    for(int l = 0;l <= n;l ++) {
                        if(k <= i-n) {
                            ans -= f[k][l] * (1ll<<(i-n-k));
                        }
                        else {
                            ans -= f[k][l] * g[j][k-i+n][l];
                        }
                    }
                }
                f[i][j] = ans;
            }
        }
        LL ans = 0;
        for(int i = 1;i <= m;i ++) {
            for(int j = 0;j <= n;j ++) {
                ans += f[i][j] * (1ll<<(m-i));
            }
        }
        printf("%lld\n",ans);
    }
}
