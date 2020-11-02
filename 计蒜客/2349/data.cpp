#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 32e5 + 10;
const int mod = 998244353;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

mt19937 rd(time(0));

int randlr(int l,int r) {
    return rd() % (r-l+1) + l;
}

struct haha {
    int x1,x2,y1,y2;
}a[SZ];

int main() {
    freopen("D.in","w",stdout);
    int n = 5;
    for(int i = 1;i <= n;i ++) {
        a[i].x1 = randlr(1,5e5);
        a[i].x2 = randlr(1,5e5);
        a[i].y1 = randlr(1,5e5);
        a[i].y2 = randlr(1,5e5);
        if(a[i].x1 > a[i].x2) swap(a[i].x1,a[i].x2);
        if(a[i].y1 > a[i].y2) swap(a[i].y1,a[i].y2);
    }
    printf("1\n%d\n",n);
    for(int i = 1;i <= n;i ++) {
        printf("%d %d %d %d\n",a[i].x1-1,a[i].y1-1,a[i].x2,a[i].y2);
    }
}
