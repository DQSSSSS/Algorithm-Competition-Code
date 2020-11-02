#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2000100;
const int INF = 1e9 + 10;
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

LL ksm(LL a,LL b) {
    LL ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

char s[SZ],t1[SZ],t2[SZ],Ans[SZ];
int d[SZ];

int main() {
    scanf("%s",s);
    int n = strlen(s);
    for(int k = 1;k <= 26*26;k *= 26) {
        for(int i = 0;i < n;i ++) t1[i] = 'a' + (i / k) % 26;
        printf("? %s\n",t1); fflush(stdout);
        scanf("%s",t2);
        for(int i = 0;i < n;i ++) d[i] += (t2[i] - 'a') * k;
    }
    for(int i = 0;i < n;i ++) Ans[d[i]] = s[i];
    printf("! %s",Ans);
    return 0;
}

