#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2e5 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0'; a = getchar(); }
    if(flag) n = -n;
    return n;
}

int f[5000010];

int get_nxt(int d,int i)
{
    int pos = i;
    d ^= 1 << pos; pos --;
    while(pos >= 0 && (d & (1 << pos))) pos --;
   // cout << pos << " " << d << endl;
    if(pos < 0 || d & (1 << pos)) return -1;
    d ^= 1 << pos;
    return d;
}

void print(int d)
{
    for(int i = 19;i >= 0;i --)
        cout << (d >> i & 1);
}

int dfs(int now)
{
	if(f[now] != -1) return f[now];
    for(int i = 0;i <= 20;i ++)
	{
        if(now & (1 << i))
		{
            int d = get_nxt(now,i);
            if(d == -1) continue;
			//print(now); cout << " "; print(d); puts("");
            int nx = dfs(d) ^ 1;
            if(nx == 1) {f[now] = 1; break; }
		}
	}
	if(f[now] == -1) f[now] = 0;
    return f[now];
}

int main()
{
	//freopen("in.txt","r",stdin); freopen("my.txt","w",stdout);
	memset(f,-1,sizeof(f));
    for(int i = 0;i <= (1 << 20);i ++) f[i] = dfs(i);
    int T = read();
    //cout << f[0] << endl;
    //for(int i = 0;i < 5;i ++) cout << f[i] << endl;;
   // for(int i = 0;i <= 20;i ++) f[(1 << i) - 1] = 0;
    while(T --)
	{
        int n = read();
        int ans = 0;
        for(int i = 1;i <= n;i ++)
        {
            int k = read(),now = 0;
            while(k --)
            {
            	int x = read();
                now |= 1 << (20 - x);
            }
			ans ^= f[now];
			cout << f[now] << endl;
        }
        if(ans) puts("YES");
        else puts("NO");
	}
	return 0;
}



