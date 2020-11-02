#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 1000010;
const LL INF = 1000000010;
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

char b[SZ],s[SZ];
int a[SZ];

int main()
{
    int T = read();
    while(T --)
	{
        int n;
        scanf("%d%s",&n,s + 1);
        for(int i = 1;i <= n - 1;i ++)
            if(s[i] == s[i + 1]) a[i] = 0;
            else if(s[i] < s[i + 1]) a[i] = 1;
            else a[i] = -1;
        int f = 0;
        for(int i = n - 1;i >= 1;i --)
		{
            if(a[i] == 1) f = 1;
            if(a[i] == -1) f = -1;
            if(f == 0) b[i] = '>';
            else b[i] = f == 1 ? '<' : '>';
		}
        for(int i = 1;i <= n - 1;i ++) printf("%c",b[i]); puts("");
	}
	return 0;
}



