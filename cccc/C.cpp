#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n; 
}

char s[110];
int jz[110],a[110],b[110],ans[110];
int n,na,nb,nans;

void input(int a[],int &n)
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	for(int i = n;i >= 1;i --)
		a[n - i + 1] = s[i] - '0';
}

int main()
{
	input(jz,n); input(a,na); input(b,nb);
	nans = 0;
	int x = 0;
	for(int i = 1;;i ++)
	{
		if(i > max(na,nb) && x == 0) {nans = i; break;}
		x += a[i] + b[i];
		int d = (i > n ? 10 : (jz[i] == 0 ? 10 : jz[i]));
		ans[i] = x % d;
		x /= d;
	}
	while(nans > 1 && ans[nans] == 0) nans --;
	for(int i = nans;i >= 1;i --) cout << ans[i];
	return 0;
}


