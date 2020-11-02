#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

mt19937 rd(time(0));

int a[SZ];

int main() {
    freopen("1.in","w",stdout);
    srand(time(0));
    int T = 3;
    printf("%d\n",T);
    while(T --) {
        int n = 50000;
        printf("%d\n",n);
        for(int i = 1;i <= n;i ++) a[i] = i;
        random_shuffle(a+1,a+1+n);
        for(int i = 1;i <= n;i ++) printf("%d ",a[i]); puts("");
        random_shuffle(a+1,a+1+n);
        for(int i = 1;i <= n;i ++) printf("%d ",a[i]); puts("");
    }
}
