#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int SZ = 1e7 + 10;

const ULL W = -1,N = 10000000,BLOCK = W / N;
/// BLOCK : 1844674407370
vector<ULL> g[4010];
ULL A,B,L,n,s0;

void work1()
{
	//cout << 4325665515877804703ull / BLOCK << endl; ///2344947  1104
	ULL qw = n / N;
	ULL qwk = L / qw;
	ULL l = max(0,(int)qwk - 2000),r = min((int)N,(int)qwk + 2000);
	//cout << qw << " " << qwk << " " << l << " " << r << endl;
	/// 2343843 2347843
	LL t = 0;
	for(int i = 1;i <= n;i ++)
	{
		ULL nownum = s0 / BLOCK;
		if(nownum < l) t ++;
		else if(nownum <= r)
		{
			ULL num = nownum - l;
			g[num].push_back(s0);
	//		cout << num << " " << i << " " << s0 << endl;
		}
		//cout << nownum << " ";
		s0 = s0 * A + B;
	}
	//cout << BLOCK << endl;
	for(int i = 0;i <= 4002;i ++)
	{
		sort(g[i].begin(),g[i].end());
		LL sz = g[i].size();
		//cout << i << " " << sz << " " << t << endl;
	//	for(int j = 0;j < sz;j ++) cout << g[i][j] << " "; puts("");
		if(t + sz >= L)
		{
			for(int j = 0;j < sz;j ++)
			{
				if(t + j + 1 == L)
				{
					cout << g[i][j] <<endl;
					exit(0);
				}
			}
		}
		else t += sz;
	}	
}

ULL a[SZ];

void work2()
{
	int t = 0;
	for(int i = 1;i <= n;i ++)
	{
		a[++ t] = s0;
		s0 = s0 * A + B;
	}
	sort(a + 1,a + 1 + t);
	cout << a[L] << endl;;
}

int main()
{
	cin >> A >> B >> L >> n >> s0;
	if(n <= 1e7) work2();
	else work1();
	return 0;
}

/**
5 7 2345843 10000000 13

4325665515877804703
**/
