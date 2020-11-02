#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e5 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int a[33][SZ];
char s[SZ];

int main() {
    int T = read();
    for(int cc = 1;cc <= T;cc ++) {
        int n = read(),q = read();
        scanf("%s",s + 1);
        for(int i = 1;i <= n;i ++) {
            for(int j = 0;j < 26;j ++) a[j][i] = 0;
            a[s[i]-'A'][i] ++;
        }
        for(int i = 0;i < 26;i ++)
            for(int j = 1;j <= n;j ++)
                a[i][j] += a[i][j-1];
        int ans = 0;
        while(q --) {
            int l = read(),r = read();
            int ji = 0,ou = 0;
            for(int i = 0;i < 26;i ++) {
                int x = a[i][r] - a[i][l-1];
                if(x&1) ji++;
                else ou ++;
            }
            if(ji <= 1) ans ++;
        }
        printf("Case #%d: %d\n",cc,ans);
    }
}
