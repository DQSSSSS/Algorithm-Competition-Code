#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;

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
    int n = read(),x = read(),y = read();
    scanf("%s",s+1);
    int ans = 0;
    for(int i = n;i > n-y;i --) {
        if(s[i] != '0') ans ++;
    }
    if(s[n-y] != '1') ans ++;
    for(int i = n-y-1;i > n-x;i --) {
        if(s[i] != '0') ans ++;
    }
    cout << ans << endl;
}
