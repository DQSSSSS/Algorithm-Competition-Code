#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 2e5 + 10;
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

int main() {
    int T = read();
    while(T --) {
        int a[11] = {0};
        for(int i = 0;i < 5;i ++) {
            int x = read();
            a[x] ++;
        }
        int maxn = 0,id = 0;
        for(int i = 1;i <= 5;i ++) {
            if(a[i] > maxn) maxn = a[i],id = i;
        }
        printf("%d\n",id);
    }
    return 0;
}
