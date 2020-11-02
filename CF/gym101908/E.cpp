#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
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

char s1[SZ],s2[SZ];

int main() {
    int ans = 0;
    scanf("%s%s",s1 +1,s2 +1);
    int n = strlen(s1 + 1);
    int m = strlen(s2 + 1);
    for(int i = 1;i + m - 1<= n;i ++) {
        bool flag = 0;
        for(int j = 1;j <= m;j ++)
            if(s1[i+j-1] == s2[j]) {
                flag = 1;
                break;
            }
        if(!flag) ans ++;
    }
    cout << ans << endl;
}

