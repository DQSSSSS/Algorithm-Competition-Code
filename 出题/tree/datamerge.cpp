#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const LL INF = 1e9 + 10;
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

string name = "tree";

int main()
{
	freopen("tree0.out","w",stdout);
	for(int i = 1;i <= 10;i ++)
	{
		string s,in,out;
		s += name;
		if(i <= 9) s += (char)(i + '0');
		else s += (char)(i / 10 + '0'),s += (char)(i % 10 + '0');
		in += s; in += ".out";
		freopen(in.c_str(),"r",stdin);
		
		{
			LL x;
			while(~scanf("%lld",&x)) cout <<x << endl;
		/*	int n = read();
			printf("%d\n",n);
			for(int i = 1;i < n;i ++)
			{
				int u = read(),v = read();
				LL w = read();
				printf("%d %d %lld\n",u,v,w);
			}
			int m = read();
			cout << m << endl;
			for(int i = 1;i <= m;i ++)
			{
				int x = read(),y = read(),z = read();
				printf("%d %d %d\n",x,y,z);
			}*/
		//	puts("");
		}
		fclose(stdin);
	}
}


