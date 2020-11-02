#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 3010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar();  }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m;

bool bits[SZ][SZ][55];

void add(int x,int y,int id,int d)
{
    //cout << x << " " << y << endl;
    //if(x == 0 || y == 0) return ;
    for(int i = x;i <= n;i += i & -i)
        for(int j = y;j <= n;j += j & -j)
            bits[i][j][id] += d;
}

int ask(int x,int y,int id)
{
    //if(x == 0 || y == 0) return 0;
    int ans = 0;
    for(int i = x;i > 0;i -= i & -i)
        for(int j = y;j > 0;j -= j & -j)
            ans += bits[i][j][id];
    return ans;
}

int ask(int x1,int y1,int x2,int y2,int id)
{
    return ask(x2,y2,id) - ask(x1 - 1,y2,id) - ask(x2,y1 - 1,id) + ask(x1 - 1,y1 - 1,id);
}

int main()
{
    n = read() + 1,m = read();
    for(int cc = 1;cc <= m;cc ++)
    {
        char opt[3];
        scanf("%s",opt);
        int x1 = read() + 1,y1 = read() + 1,x2 = read() + 1,y2 = read() + 1;
        if(opt[0] == 'P')
        {
            int k = read();
            while(k --)
            {
                int id = read(),x = read() % 2;
                add(x1 - 1,y1 - 1,id,x); add(x2,y2,id,x);
                add(x1 - 1,y2,id,-x); add(x2,y1 - 1,id,-x);
            }
        }
        else
        {
            for(int i = 1;i <= 50;i ++)
            {
                int x = ask(x1,y1,x2,y2,i);
                cout << x << " ";
                //printf("%d%c",x % 2 == 0 ? 1 : 2,i == 50 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
