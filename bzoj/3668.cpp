#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
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

int n,m;

struct haha
{
    char s[5];
    int x;
}l[SZ];

int opt(int x,char c[],int yy,int pos)
{
    int y = yy & (1 << pos);
    if(c[0] == 'O') return x | y;
    if(c[0] == 'X') return x ^ y;
    if(c[0] == 'A') return x & y;
}

int main()
{
    n = read(),m = read();
    for(int i = 1;i <= n;i ++)
        scanf("%s%d",l[i].s,&l[i].x);
    int ans = 0;
    for(int pos = 30;pos >= 0;pos --)
    {
        int x = 1 << pos;
        if((x | ans) > m) continue;
        int y = 0;
        for(int i = 1;i <= n;i ++)
        {
            x = opt(x,l[i].s,l[i].x,pos);
            y = opt(y,l[i].s,l[i].x,pos);
        }
        //cout << pos << " " << x << " " << y << endl;
        if(y == (1 << pos)) continue;
        if(x == (1 << pos)) ans |= 1 << pos;
    }
    for(int i = 1;i <= n;i ++)
    {
        if(l[i].s[0] == 'O') ans |= l[i].x;
        if(l[i].s[0] == 'X') ans ^= l[i].x;
        if(l[i].s[0] == 'A') ans &= l[i].x;
    }
    printf("%d\n",ans);
    return 0;
}
/*

& 0101
| 0110
^ 0111

*/
