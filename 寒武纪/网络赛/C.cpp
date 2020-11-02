#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1000000010;

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

int a[SZ];

int main()
{
	for(int n = 1;n <= 100;n ++)
	{
		int ans = 0;
		for(int k = 1;k <= n - 1;k ++)
			for(int m = 1;m <= k;m ++)
				if(k * m <= n && k * m > k + 1)
					ans ++;
		cout << ans << " " << n  << endl;
		
		/*int ans = 0;
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n;j ++)
				if(i % j == i / j)
					ans ++;	
		a[n] = ans;
		cout << a[n] << " " << n<< endl;*/
	}
	return 0;
}
/*
0 1
0 2
1 3
2 4
3 5
4 6
5 7
7 8
8 9
10 10
11 11
13 12
14 13
16 14
18 15
20 16
21 17
24 18
25 19
27 20
29 21
31 22
32 23
36 24
37 25
39 26
41 27
44 28
45 29
48 30

*/
