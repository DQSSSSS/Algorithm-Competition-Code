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
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int a[SZ],b[SZ];

int main()
{
	int n = read(),m = read(),k = read();
    for(int i = 1;i <= n;i ++)
        a[b[i] = read()] = 1;
    sort(b + 1,b + 1 + n);
    if(k == 1) { cout << n << endl; return 0; }
    int l = 1,r = 1,ans = 0,now = a[1],p = b[1] == 1 ? 1 : 0;
    while(l <= r && r <= 1e6)
	{
        while(r < 1e6 && r - l + 1 < m) r ++,now += a[r],p += a[r];
     //   cout << l << " " << r << " " << now << " " << ans << endl; system("pause");
        if(now >= k)
		{
			ans += now - k + 1;
			for(int i = 0;i <= now - k;i ++) a[b[p - i]] = 0;
			now = k - 1;
		}
		now -= a[l]; l ++;
	}
	cout <<ans << endl;

	return 0;
}




