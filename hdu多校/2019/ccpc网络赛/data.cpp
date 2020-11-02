#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

mt19937 randint(time(0));

int randlr(int l,int r) {
    return randint() % (r-l+1) + l;
}

void randtree(int n) {
    for(int i = 2;i <= n;i ++)
        printf("%d %d %d\n",i,randint()%(i-1)+1,randlr(1,10));
}

int a[SZ];

int main() {
	freopen("3.in","w",stdout);
    /*int t1 = randlr(1,1e9);
    int t2 = randlr(1,1e9);
    int p = 2;
    int q = 5;
    int n = 1e9;
    int m = 2e5;
    printf("%d %d %d %d %d %d\n",t1,t2,p,q,n,m);
    while(m --) {
        int x = randlr(0,1e9/p)*p;
        int y = randlr(0,1e9/q)*q;
        int v = randlr(1,1e9);
        printf("%d %d %d\n",x,y,v);
    }*/
    int T = 3;
    printf("%d\n",T);
    while(T --) {
        int n = 10,m = 10;
        printf("%d %d\n",n,m);
        for(int i = 1;i <= n;i ++) {
            int x = randlr(1,100);
            printf("%d ",x);
        }
        puts("");
        while(m --) {
            int l = randlr(1,n);
            int r = randlr(1,n);
            if(l > r) swap(l,r);
            printf("%d %d\n",l,r);
        }
    }
	return 0;
}

