#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 5e6 + 10;
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

int inv(int x) {
    int ans = 0;
    for(int i = 0;i < 8;i ++) ans |= (x>>i&1)<<(8-i-1);
    return ans;
}

int main() {
    scanf("%s",s);
    int n = strlen(s);
    for(int i = 0;i < n;i += 3) {
        int x = (inv(s[i]) << 16) | (inv(s[i+1])<<8) | inv(s[i+2]);
        printf("%d %d %d %d ",x>>18&63,x>>12&63,x>>6&63,x&63);
    }
}
