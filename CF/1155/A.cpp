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

char s[SZ];

int main() {
    int n = read();
    scanf("%s",s + 1);
    for(int i = 1;i < n;i ++) {
        if(s[i] > s[i+1]) {
            puts("YES");
            cout << i << " " << i + 1;
            return 0;
        }
    }
    puts("NO");
    return 0;
}
