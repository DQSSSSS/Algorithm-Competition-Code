#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e6 + 10;
const int mod = 998244353;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

char s[SZ];
int a[SZ],sum[SZ];

int main() {
    scanf("%s",s+1);
    int n = strlen(s+1);
    for(int i = 1;i <= n;i ++) {
        if(s[i] == ')') a[i] = -1;
        else a[i] = 1;
    }
    for(int i = 1;i <= n;i ++) {
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = n;i >= 1;i --) {
        if(s[i] == ')') {
            int x = sum[i] + 2;
            int rst = n - i;
            if(rst >= x && (rst-x)%2==0) {
                for(int j = 1;j < i;j ++) printf("%c",s[j]);
                printf("%c",'(');
                for(int j = 1;j <= x;j ++) printf(")");
                for(int j = 1;j <= (rst-x)/2;j ++) printf("()");
                puts("");
                break;
            }
        }
    }

    for(int i = n;i >= 1;i --) {
        if(s[i] == '(') {
            int x = sum[i] - 2;
            int rst = n - i;
            if(x >= 0 && rst >= x && (rst-x)%2==0) {
                for(int j = 1;j < i;j ++) printf("%c",s[j]);
                printf("%c",')');
                for(int j = 1;j <= (rst-x)/2;j ++) printf("(");
                for(int j = 1;j <= (rst-x)/2;j ++) printf(")");
                for(int j = 1;j <= x;j ++) printf(")");
                puts("");
                break;
            }
        }
    }
}
