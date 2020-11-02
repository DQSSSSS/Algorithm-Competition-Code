#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 200010;
const LL INF = 2e18;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n;
struct haha
{
	LL a,b,c;
	int id;
}a[SZ];

bool cmp(haha a,haha b)
{
    LL l = a.c * (b.a + b.b);
    LL r = b.c * (a.a + a.b);
    if(l != r) return l > r;
    return a.id < b.id;
}

int main()
{
    while(~scanf("%d",&n))
	{
        for(int i = 1;i <= n;i ++)
			a[i].a = read(),a[i].b = read(),a[i].c = read(),a[i].id = i;
        sort(a + 1,a + 1 + n,cmp);
        for(int i = 1;i <= n;i ++) printf("%d%c",a[i].id,i == n ? '\n' : ' ');
	}
	return 0;
}

/*
18446744073709551615
4000000000000000000
*/


