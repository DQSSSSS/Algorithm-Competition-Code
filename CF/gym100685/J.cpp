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

bool cmp(int x,int y) {
    printf("1 %d %d\n",x,y); fflush(stdout);
    char s[5];
    scanf("%s",s);
    return s[0] == 'Y';
}

int a[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) a[i] = i;
    stable_sort(a+1,a+1+n,cmp);
    for(int i = 0;i <= n;i ++) printf("%d ",a[i]);
}
