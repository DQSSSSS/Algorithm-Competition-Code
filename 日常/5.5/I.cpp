#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' ||a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int a[9000010],t[9000010],c[9000010];
vector<int> g;

bool check(int n)
{
	if(62 <= n && n <= 865) return true;
	return false;
	for(int x = 2;x <= n;x ++)
		for(int y = 2;y <= x;y ++)
			c[x * y] = t[x * y] = 0,a[x] = 0;
	g.clear();
	for(int x = 2;x <= n;x ++)
		for(int y = 2;y <= x;y ++)
			if(++ t[x * y] == 2) g.push_back(x * y);
	for(int d = 4;d <= n * 2;d ++)
	{
		int m = 0;
		for(int x = 2;x <= d - 2;x ++)
		{
			int y = d - x;
			if(x > y) continue;
			if(t[x * y] >= 2) m ++;
			m --;
		}
		if(m == 0) a[d] = 1; 
	}
	for(int i = 0;i < g.size();i ++)
	{
		int k = g[i],cnt = 0;
		for(int x = 2;x <= n;x ++)
		{
			if(k % x == 0)
			{
				int y = k / x;
				if(x <= y && y <= n)
					if(a[x + y]) cnt ++;
			}
		}
		if(cnt == 1) c[k] = 1;
	}
	
	int cnt = 0;
	for(int d = 4;d <= n * 2;d ++)
	{
		if(!a[d]) continue;
		int m = 0;
		for(int x = 2;x <= d - 2;x ++)
		{
			int y = d - x;
			if(x > y) continue;
			if(c[x * y]) m ++;
		}
		if(m == 1) cnt ++;
	}
	if(cnt == 1) return true;
	return false;
}

int main()
{
	int T = read();
	while(T --)
	{
        int n = read();
        if(check(n)) puts("YES");
        else puts("NO");
	}
	return 0;
}

/**
   4
   5   6
   6   7   8
   7   8   9  10
   8   9  10 *11  12
   9  10 *11  12  13  14
  10 *11  12  13  14  15  16
 *11  12  13  14  15  16  17  18
  12  13  14  15  16  17  18  19  20
  13  14  15  16  17  18  19  20  21  22
  14  15  16  17  18  19  20  21  22  23  24
  15  16  17  18  19  20  21  22  23  24  25  26
  16  17  18  19  20  21  22  23  24  25  26  27  28
   4
   6   9
   8  12  16
  10  15  20  25
  12  18  24 *30  36
  14  21 *28  35  42  49
  16 *24  32  40  48  56  64
 *18  27  36  45  54  63  72  81
  20  30  40  50  60  70  80  90 100
  22  33  44  55  66  77  88  99 110 121
  24  36  48  60  72  84  96 108 120 132 144
  26  39  52  65  78  91 104 117 130 143 156 169
  28  42  56  70  84  98 112 126 140 154 168 182 196

  [62,865]
  
**/
