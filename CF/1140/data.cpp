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

void randtree(int n) {
    for(int i = 2;i <= n;i ++)
        printf("%d %d\n",i,randint()%(i-1)+1);
}

int randlr(int l,int r) {
    return randint() % (r-l+1) + l;
}

int a[SZ];

int main() {
	freopen("data.in","w",stdout);
    int n = randlr(2,20);
    int k = randlr(2,20);
    printf("%d %d\n",n,k);
    for(int i = 1;i <= n;i ++) {
        int x = randlr(1,3*k);
        if(x >= k + 1) x = -1;
        printf("%d ",x);
    }
    puts("");
   // randtree(n);
	return 0;
}


