#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1100010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}
char s[100050];
int main() {
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		int ans=n+1;
		int tmp=0;
		//int t=m;
		for (int i=2;i<=m;i++)
		if (s[i]!='L') tmp++;
		
		ans=min(ans,tmp);
		
		tmp=0;
		
		for (int i=m;i<n;i++)
		if (s[i]!='R') tmp++;
		ans=min(ans,tmp);
		
		printf("%d\n",ans);
	}
}

