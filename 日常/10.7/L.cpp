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
const int SZ = 500010;
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

int get(int y,int m,int d)
{
    if(m == 1 || m == 2)
        y --,m += 12;
    int c = y / 100;
    y %= 100;
    int w = c/4 - 2*c + y + y/4 + (13*(m+1)/5)+d-1;
    w = (w % 7 + 7) % 7;
    return w;
}

int main()
{
    int T = read();
    for(int cc = 1;cc <= T;cc ++)
    {
        int y,m,d;
        scanf("%d-%d-%d",&y,&m,&d);
        int hour,min,se;
        scanf("%d:%d:%d",&hour,&min,&se);
        printf("Case #%d: ",cc);
        if(1 <= m && m <= 2) puts("PST");
        else if(4 <= m && m <= 10) puts("PDT");
        else if(m == 12) puts("PST");
        else
        {
            if(m == 3)
            {
                int t = 0;
                for(int i = 1;i <= d;i ++)
                {
                    int w = get(y,m,i);
                    if(w == 0) t ++;
                }
                if(t <= 1) puts("PST");
                else if(t > 2) puts("PDT");
                else
                {
                    if(hour <= 1) puts("PST");
                    else if(hour >= 3) puts("PDT");
                    else puts("Neither");
                }
            }
            else
            {
                int t = 0;
                for(int i = 1;i <= d;i ++)
                {
                    int w = get(y,m,i);
                    if(w == 0) t ++;
                }
                if(t == 0) puts("PDT");
                else if(t >= 2) puts("PST");
                else
                {
                    if(hour < 1) puts("PDT");
                    else if(hour >= 2) puts("PST");
                    else puts("Both");
                }
            }
        }
    }
    return 0;
}
