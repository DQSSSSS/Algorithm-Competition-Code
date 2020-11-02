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

int S[SZ];
char s[SZ];

int main() {
    scanf("%s",s+1);
    int k = read(),n = strlen(s+1);
    int top = 0;
    for(int i = 1;i <= n;i ++) {
        while(top && s[S[top]] > s[i]) top --;
        S[++ top] = i;
    }
    if(top >= k) {
        for(int i = 1;i <= k;i ++) printf("%c",s[S[i]]);
    }
    else {
        top = 0;
        for(int i = 1;i <= n;i ++) {
            while(top && s[S[top]] > s[i]) {
                if(top + n - i + 1 == k) {
                    for(int j = 1;j <= top;j ++) printf("%c",s[S[j]]);
                    for(int j = i;j <= n;j ++) printf("%c",s[j]);
                    return 0;
                }
                top --;
            }
            S[++ top] = i;
        }
    }
}
