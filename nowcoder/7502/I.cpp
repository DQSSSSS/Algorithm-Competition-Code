#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
typedef pair<double, double> pdd;
const int SZ = 2000100;
const double INF = 1e10 + 10;
const int mod = 998244353;
const LD eps = 1e-6;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

char s[2020];
char t[2020];
int f[2020][2020];

int main() {
    while(~scanf("%s%s",s+1,t+1)) {
        int n = strlen(s+1);
        int m = strlen(t+1);
        int ans = 0;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                if(s[i] == t[j]) {
                    f[i][j] = f[i-1][j-1] + 2;
                } else {
                    f[i][j] = max(f[i-1][j],f[i][j-1]);
                    if(s[i] < t[j]) {
                        ans = max(ans, f[i-1][j-1] + 2 + n-i + m-j);
                    }
                }
                ans = max(ans, f[i][j] + m-j);
            }
        }
        printf("%d\n",max(ans, m));
    }
}
