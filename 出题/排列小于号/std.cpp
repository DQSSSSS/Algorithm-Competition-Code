#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
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

int a[SZ],b[SZ];

void work(int n) {
    for(int i = 0;i <= n;i ++) a[i] = i,b[i] = 0;
    do {
        int t = 0;
        for(int i = 1;i < n;i ++) {
            if(a[i] < a[i+1]) t ++;
        }
        b[t] ++;
    }while(next_permutation(a+1,a+1+n));
    for(int i = 0;i < n;i ++) printf("%10d",b[i]); puts("");
}

int main() {
    for(int n = 2;n <= 15;n ++) {
        work(n);
    }
}
