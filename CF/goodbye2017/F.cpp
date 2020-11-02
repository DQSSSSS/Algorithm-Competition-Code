#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

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

int n,m;

LL pos[SZ],ans = 0;
LL nx[SZ],pr[SZ];
char c[SZ];


int main()
{
	scanf("%d",&n);
	bool flag = 0;
	for(int i = 1;i <= n;i ++)
	{
		char s[2];
		scanf("%I64d%s",&pos[i],s);
		c[i] = s[0];
		if(c[i] == 'G') flag = 1;
	}
	
	if(!flag)
	{
		LL bl,rl;
		bl = rl = -1;
		for(int i = 1;i <= n;i ++)
		{
			if(c[i] == 'B') ans += bl == -1 ? 0 : pos[i] - pos[bl],bl = i;
			if(c[i] == 'R') ans += rl == -1 ? 0 : pos[i] - pos[rl],rl = i;
		}
		cout << ans << endl;
		return 0;
	}
	
	
	for(int i = 1;i <= n;i ++)
	{
		if(c[i] == 'G')
		{
			LL bl,rl;
			bl = rl = i;
			for(int j = i - 1;j >= 1;j --)
			{
				if(c[j] == 'B') ans += pos[bl] - pos[j],bl = j;
				if(c[j] == 'R') ans += pos[rl] - pos[j],rl = j;
			}
			break;
		}
	}
	
	for(int i = n;i >= 1;i --)
	{
		if(c[i] == 'G')
		{
			LL bl,rl;
			bl = rl = i;
			for(int j = i + 1;j <= n;j ++)
			{
				if(c[j] == 'B') ans += pos[j] - pos[bl],bl = j;
				if(c[j] == 'R') ans += pos[j] - pos[rl],rl = j;
			}
			break;
		}
	}
	
	/*
	cout << n <<endl;
	for(int i = 1;i <= tot;i ++) printf("%I64d ",pos[i]); puts("");
	for(int i = 1;i <= n;i ++)
		printf("%I64d %I64d %c\n",l[i].l,l[i].r,c[i]);
	
	for(int i = 1;i <= n;i ++)
		if(c[i] == 'R') printf("R : %d %d\n",pr[l[i].l],nx[l[i].r]);
		else if(c[i] == 'B') printf("B : %d %d\n",pr[l[i].l],nx[l[i].r]);
	*/
	
	for(int L = 1,R;L <= n;L = R)
	{
		R = L + 1;
		//
		while(R <= n && c[R] != 'G') R ++;
		//cout << L << " " << R << endl;
		if(c[L] != 'G') continue;
		if(R > n) break;
		
		LL bm = 0,rm = 0,bl,rl;
		bl = rl = L;
		for(int i = L + 1;i <= R;i ++)
		{
			if(c[i] == 'B' || i == R) bm = max(bm,pos[i] - pos[bl]),bl = i;
			if(c[i] == 'R' || i == R) rm = max(rm,pos[i] - pos[rl]),rl = i;
		}
		LL len = pos[R] - pos[L];	
		ans += min(len * 2,len * 3 - bm - rm);
	//	cout << len << " " << " " << bm << " " << rm << endl;
	}
	printf("%I64d\n",ans);
	return 0;
}

