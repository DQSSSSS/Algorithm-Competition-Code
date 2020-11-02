#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 100010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
const LD eps = 1e-8;
LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int main() {
    freopen("I.in","w",stdout);
    int T = 20000 - 29;
    printf("%d\n",20000);
    while(T --) {
        int n = 5;
        printf("%d",rand()%9+1);
        for(int i = 2;i <= n;i ++) {
            printf("%d",rand()%10);
        }
        puts("");
    }
    T = 29;
    while(T --) {
        int n = 1e5;
        printf("%d",rand()%9+1);
        for(int i = 2;i <= n;i ++) {
            printf("%d",rand()%10);
        }
        puts("");
    }
}
