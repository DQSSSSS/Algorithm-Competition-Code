#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
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

char s[SZ],ans[SZ];
int n;

bool check() {
    if(n & 1) return false;
    if(s[1] != '?' && s[1] == ')') return false;
    if(s[n] != '?' && s[n] == '(') return false;
    ans[1] = '(';
    ans[n] = ')';

    int d = 0;
    for(int i = 2;i <= n-1;i ++) {
        if(s[i] == ')') ans[i] = ')',d --;
        else ans[i] = '(',d ++;
    }

    for(int i = n-1;i >= 1;i --) {
        if(s[i] == '?' && d > 0) {
            ans[i] = ')';
            d -= 2;
            if(d == 0) break;
        }
    }
    d = 0;
    for(int i = 1;i <= n;i ++) {
        if(ans[i] == '(') d ++;
        else d --;
        if(i < n && d == 0) return false;
    }
    if(d == 0) return true;
    return false;
}

int main() {
    n = read();
    scanf("%s",s+1);
    if(check()) printf("%s\n",ans+1);
    else puts(":(");
}
