//litianfeng
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;

const int p=1e9+7;
int T,n,Q,v[21],c[21];
int f[21][10005];
inline int read()
{
    int k=0;
    char f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar() )
        if(c=='-')
            f=-1;
    for(;isdigit(c);c=getchar() )
        k=k*10+c-'0';
    return k*f;
}

int tmp[33];

int main()
{
    T=read();
    while (T--)
    {
       // memset(f,0,sizeof f);
        n=read();Q=read();
        for (int i=1;i<=n;i++)
            v[i]=read(),c[i]=read();

        f[0][0]=1;//f even ,g odd
        for (int i=1;i<=n;i++) {
        	for(int k = 0;k < v[i];k ++) tmp[k] = 0;
        	int len = (1 << c[i]) - 1;
            for (int j=0;j<=10000;j++) {
				int id = j % v[i];
				(tmp[id] += f[i - 1][j]) %= p;
				if(j / v[i] > len) 
					(tmp[id] -= f[i - 1][j - (len + 1) * v[i]]) %= p;
				f[i][j] = tmp[id];
			}
        }
        for (int i=1;i<=Q;i++)
        {
            int x;
            x=read();
            f[n][x] += p; f[n][x] %= p;
            printf("%d\n",f[n][x]);
        }

    }
    return 0;
}
