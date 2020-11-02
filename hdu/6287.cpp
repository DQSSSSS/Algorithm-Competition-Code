#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 100010;
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

const int pri[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313};
int id[110],a[SZ];
LL b[70][SZ];
vector<int> g[SZ];

bool check(int l,int r,int x)
{
	for(int j = 0;j < 65;j ++)
	{
		int p = pri[j];
		if(x % p) continue;
		int t = 0;
		while(x % p == 0) x /= p,t ++;
		int i = id[p];
		if(b[i][r] - b[i][l - 1] < t) return false;
	}
    if(x != 1)
	{
		/*for(int i = 0;i < g[x].size();i ++)
			if(l <= g[x][i] && g[x][i] <= r) return true;
		return false;*/
        int L = lower_bound(g[x].begin(),g[x].end(),l) - g[x].begin();
        int R = lower_bound(g[x].begin(),g[x].end(),r) - g[x].begin();
        if(R < g[x].size() && L == R && g[x][L] == r) return true;
		if(L >= R) return false;
	}
	return true;
}

int main()
{
	id[2] = 0,id[3] = 1,id[5] = 2,id[7] = 3,id[11] = 4,id[13] = 5,id[17] = 6,id[19] = 7,id[23] = 8,id[29] = 9,id[31] = 10,id[37] = 11,id[41] = 12,id[43] = 13,id[47] = 14,id[53] = 15,id[59] = 16,id[61] = 17,id[67] = 18,id[71] = 19,id[73] = 20,id[79] = 21,id[83] = 22,id[89] = 23,id[97] = 24,id[101] = 25,id[103] = 26,id[107] = 27,id[109] = 28,id[113] = 29,id[127] = 30,id[131] = 31,id[137] = 32,id[139] = 33,id[149] = 34,id[151] = 35,id[157] = 36,id[163] = 37,id[167] = 38,id[173] = 39,id[179] = 40,id[181] = 41,id[191] = 42,id[193] = 43,id[197] = 44,id[199] = 45,id[211] = 46,id[223] = 47,id[227] = 48,id[229] = 49,id[233] = 50,id[239] = 51,id[241] = 52,id[251] = 53,id[257] = 54,id[263] = 55,id[269] = 56,id[271] = 57,id[277] = 58,id[281] = 59,id[283] = 60,id[293] = 61,id[307] = 62,id[311] = 63,id[313] = 64;
	/*for(int i = 2;i * i <= 100000;i ++)
	{
		bool flag = 0;
        for(int j = 2;j * j <= i;j ++)
			if(i % j == 0) flag = 1;
        if(flag) continue;
        g.push_back(i);
	}
    for(int i = 0;i < g.size();i ++) printf("%d,",g[i]); puts("");
    for(int i = 0;i < g.size();i ++) printf("id[%d] = %d,",g[i],i);*/
    int T = read();
    while(T --)
	{
        int n = read(),m = read();
        for(int i = 1;i <= 100000;i ++) g[i].clear();
        for(int i = 1;i <= n;i ++)
		{
			a[i] = read();
            int x = a[i];
            for(int j = 2;j * j <= x;j ++)
				while(x % j == 0) x /= j;
			if(x != 1) g[x].push_back(i);
		}
        for(int k = 0;k < 65;k ++)
		{
			int p = pri[k];
            for(int i = 1;i <= n;i ++)
            {
            	int x = a[i],t = 0;
                while(x % p == 0) x /= p,t ++;
				b[k][i] = t;
            }
			for(int i = 1;i <= n;i ++)
				b[k][i] += b[k][i - 1];
		}
        while(m --)
		{
            int l = read(),r = read(),x = read();
			puts(check(l,r,x) ? "Yes" : "No");
		}
	}
	return 0;
}

