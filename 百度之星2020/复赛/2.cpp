#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1000010;
const LL INF = 1e18 + 10;
const LL mod = 998244353;

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

char a[SZ],b[SZ];
int suf[SZ];
int preA0[SZ];
int preB1[SZ];

int main() {
    int T = read();
    while(T --) {
        int n = read();
        scanf("%s%s",a+1,b+1);
        n ++; a[n]=b[n]='0';
        suf[n+1] = 0;
        for(int i = n;i >= 1;i --) {
            suf[i] = suf[i+1];
            if(a[i] != b[i]) suf[i] ++;
        }
        for(int i = 1;i <= n;i ++) {
            preA0[i] = preA0[i-1];
            preB1[i] = preB1[i-1];
            if(a[i] == '0') preA0[i] ++;
            if(b[i] == '1') preB1[i] ++;
        }

        int ans = suf[1];
        for(int i = 1;i < n;i ++) {
            int zero = preA0[i];
            int one = preB1[i];
            int tmp = zero + 1 + one;
            if(a[i+1] == '0' && b[i+1] == '1') {
                tmp += suf[i+2];
            }
            if(a[i+1] == '1' && b[i+1] == '0') {
                tmp += 2 + suf[i+2];
            }
            if(a[i+1] == '1' && b[i+1] == '1') {
                tmp += 1 + suf[i+2];
            }
            if(a[i+1] == '0' && b[i+1] == '0') {
                tmp += 1 + suf[i+2];
            }
            ans = min(ans,tmp);
        }
        printf("%d\n",ans);
    }
}

