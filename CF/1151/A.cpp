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

int a[SZ];
char s[SZ],t[] = "ACTG";

int main() {
    int n = read();
    scanf("%s",s);
    int ans = 1e9;
    for(int i = 0;i < n - 3;i ++) {
        int tmp = 0;
        for(int j = i;j < i + 4;j ++) {
            int x = j - i;
            tmp += min(abs(t[x]-s[j]),26-abs(t[x]-s[j]));
        }
        ans = min(ans,tmp);
    }
    cout << ans << endl;
}
