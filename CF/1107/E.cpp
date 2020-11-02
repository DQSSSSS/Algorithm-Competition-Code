#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 110;
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


LL f[2][SZ][SZ][SZ],a[SZ];
int t[2][SZ][SZ];
char s[SZ];

LL work(int c,int l,int r,int k) {
    if(l > r) return 0;
    if(k > t[c][l][r]) return -1e18;
    if(f[c][l][r][k]) return f[c][l][r][k];

    LL ans = 0;
    if(k == 0) {
        for(int cc = 0;cc < 2;cc ++)
            for(int i = 1;i <= t[cc][l][r];i ++)
                ans = max(ans,work(cc,l,r,i)+a[i]);
    }
    else {
        for(int i = l;i <= r;i ++) {
            if(s[i] - '0' == c && t[c][i+1][r] >= k-1) {
                ans = max(ans,work(c,l,i-1,0)+work(c,i+1,r,k-1));
            }
        }
    }
    return f[c][l][r][k] = ans;
}

int main() {
    int n = read();
    scanf("%s",s + 1);
    for(int i = 1;i <= n;i ++) a[i] = read();

    for(int i = 0;i < 2;i ++)
        for(int j = 1;j <= n;j ++) {
            t[i][j][j] = s[j] - '0' == i;
            for(int k = j + 1;k <= n;k ++)
                t[i][j][k] = t[i][j][k-1] + (s[k]-'0'==i);
        }
    cout << work(0,1,n,0) << endl;
    return 0;
}
/***
2
11
3 4
*/
