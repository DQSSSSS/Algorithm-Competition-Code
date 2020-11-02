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
	freopen("1.in","w",stdout);
    int T = 10;
    printf("%d\n",T);
    while(T --) {
        int n = randlr(2,10);
        printf("%d\n",n);
        randtree(n);
    }
	return 0;
}

