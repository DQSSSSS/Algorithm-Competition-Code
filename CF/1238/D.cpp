#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const int mod = 1e9 + 7;
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

char s[SZ];

int main() {
    int n = read();
    scanf("%s",s+1);
    LL ans = 1ll*n*(n-1)/2;
    int t = 0;
    for(int i = 1,j = 1;i <= n;i ++) {
        if(i == n || s[i+1] != s[i]) {
            int len = i - j + 1;
            if(i < n) ans -= len;
            if(j > 1) ans -= len;
            t ++;
            j = i + 1;
        }
    }
    ans += t - 1;
    printf("%lld\n",ans);
}
