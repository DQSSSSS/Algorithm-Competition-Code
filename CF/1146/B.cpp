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

char s[SZ];

int main() {
    scanf("%s",s);
    int n = strlen(s);
    int x = 0;
    for(int i = 0;i < n;i ++) if(s[i] == 'a') x ++;
    for(int i = n;i >= 0;i --) {
        if(s[i] == 'a') break;
        if(i-x == n-i) {
            for(int j = 0,p = i;j < i;j ++) {
                if(s[j] == 'a') continue;
                if(s[j] == s[p]) p ++;
                else return puts(":("),0;
            }
            s[i] = '\0';
            printf("%s",s);
            return 0;
        }
    }
    return puts(":("),0;
}
