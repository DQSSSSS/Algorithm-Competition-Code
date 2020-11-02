#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<ctime>
#include<bitset>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 200010;
const LL INF = 1000000010;
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

int val[SZ];

void change(int l,int r,int d)
{
    for(int i = l;i <= r;i ++)
        val[i] = d;
}

void roller(int l,int r)
{
    for(int i = l;i <= r;i ++)
        val[i] ^= 1;
}

int ask_sum(int l,int r)
{
    int ans = 0;
    for(int i = l;i <= r;i ++)
        ans += val[i];
    return ans;
}

int ask_ans(int l,int r)
{
    int ans = 0,tmp = 0;
    for(int i = l;i <= r;i ++)
        if(val[i] == 0) ans = max(ans,tmp),tmp = 0;
        else tmp ++;
    return max(ans,tmp);
}

int main()
{
	freopen("in.txt","r",stdin); freopen("baoli.txt","w",stdout);
    int n = read(),m = read();
    for(int i = 1;i <= n;i ++) val[i] = read();
    while(m --)
    {
        int opt = read(),x = read() + 1,y = read() + 1;
        if(opt == 0)
            change(x,y,0);
        else if(opt == 1)
            change(x,y,1);
        else if(opt == 2)
            roller(x,y);
        else if(opt == 3)
            printf("%d\n",ask_sum(x,y));
        else
            printf("%d\n",ask_ans(x,y));
    }
    return 0;
}
/*
5 233
0 1 0 0 1
1 3 4
3 4 4
4 1 3
0 2 4
4 3 4

*/
