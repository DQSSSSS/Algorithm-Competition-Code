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
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') { n = n *10 +a - '0'; a = getchar(); }
	if(flag) n = -n;
	return n;
}

int a[SZ],n,k,tmp[SZ];

bool check(int mid)
{
	for(int i = 0;i <= n + 1;i ++) tmp[i] = 0;
	for(int i = 1;i <= k;i ++)
	{
		int l = max(1,a[i] - mid + 1),r = min(n,a[i] + mid - 1);
		tmp[l] ++; tmp[r + 1] --;
	}
	for(int i = 1;i <= n;i ++) tmp[i] += tmp[i - 1];
	//for(int i = 1;i <= n;i ++) cout << tmp[i] << " "; puts("");
	for(int i = 1;i <= n;i ++) if(!tmp[i]) return false;
	return true;
}

int div()
{
	int l = 0,r = 1000;
	while(r - l > 1)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	return r;
}

int main()
{
	int T = read();
	while(T --)
	{
		n = read(),k = read();
		for(int i = 1;i <= k;i ++) a[i] = read();
		printf("%d\n",div());
	}
	return 0;
}
