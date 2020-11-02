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

int main() {
    int T = read();
    while(T --) {
        int n = read();
        int ans = 0;
        for(int i = 0;(1<<i) <= n;i ++) {
            vector<int> a1,a2;
            for(int j = 1;j <= n;j ++)
                if(j>>i&1) a1.push_back(j);
                else a2.push_back(j);
            printf("%d %d ",a1.size(),a2.size());
            for(int j = 0;j < a1.size();j ++) printf("%d ",a1[j]);
            for(int j = 0;j < a2.size();j ++) printf("%d ",a2[j]); puts("");
            fflush(stdout);
            ans = max(ans,(int)read());
        }
        printf("-1 %d\n",ans); fflush(stdout);
    }
}
