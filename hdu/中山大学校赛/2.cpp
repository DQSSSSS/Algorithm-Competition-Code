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

int read(){
    int n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int a[SZ];

int main() {
    int n;
    while(~scanf("%d",&n)) {
        for(int i = 1;i <= n;i ++) {
            scanf("%d",&a[i]);
        }
        if(n > 50) puts("YES");
        else {
            sort(a+1,a+1+n);
            bool flag = 0;
            for(int i = 1;i + 2 <= n && !flag;i ++) {
                if((LL)a[i] + a[i+1] > a[i+2])
                    flag = 1;
            }
            if(flag) puts("YES");
            else puts("NO");
        }
    }
}
