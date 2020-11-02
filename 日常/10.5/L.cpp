#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<ctime>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 1000010;
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

int opt[SZ][2],n,a[SZ];
int b[SZ];

bool jt(int a,int b)
{
//    cout << a << " " << b << endl;
    for(int i = 0;i < 3;i ++)
        if( (((a >> i) & 1) == 1 && ((b >> i) & 1) == 0) )
            return false;
    return true;
}

int ans = 0;
bool check()
{
    for(int i = 1;i <= n;i ++)
        for(int j = i + 1;j <= n;j ++)
            if(i != j)
            {
                int tmp = 0;

                if(jt(a[i],a[j])) ans ++,opt[ans][0] = i,opt[ans][1] = j,b[ans] = 0;
                if(jt(a[i],(~a[j]) & 7)) ans ++,opt[ans][0] = i,opt[ans][1] = j,b[ans] = 1;
                if(jt((~a[i]) & 7,a[j])) ans ++,opt[ans][0] = i,opt[ans][1] = j,b[ans] = 2;
                if(jt((~a[i]) & 7,(~a[j]) & 7)) ans ++,opt[ans][0] = i,opt[ans][1] = j,b[ans] = 3;

                if(jt(a[j],a[i])) ans ++,opt[ans][0] = j,opt[ans][1] = i,b[ans] = 0;
                if(jt(a[j],(~a[i]) & 7)) ans ++,opt[ans][0] = j,opt[ans][1] = i,b[ans] = 1;
                if(jt((~a[j]) & 7,a[i])) ans ++,opt[ans][0] = j,opt[ans][1] = i,b[ans] = 2;
                if(jt((~a[j]) & 7,(~a[i]) & 7)) ans ++,opt[ans][0] = j,opt[ans][1] = i,b[ans] = 3;
            //    if(tmp >= 2 || tmp == 0) return false;
            }
    if(ans < n*(n-1)/2)
    return true;
}

int main()
{
    n = read();
    for(int d = 0;d < 3;d ++)
        for(int i = 1;i <= n;i ++)
        {
            int x = read();
            a[i] |= x << d;
        }
    if(!check() || ans == 0) puts("-1");
    else
    {
        printf("%d\n",ans);
        for(int i = 1;i <= ans;i ++)
        {
            if(b[i] == 0) printf("x%d -> x%d\n",opt[i][0],opt[i][1]);
            if(b[i] == 1) printf("x%d -> !x%d\n",opt[i][0],opt[i][1]);
            if(b[i] == 2) printf("!x%d -> x%d\n",opt[i][0],opt[i][1]);
            if(b[i] == 3) printf("!x%d -> !x%d\n",opt[i][0],opt[i][1]);
        }
    }
    return 0;
}
