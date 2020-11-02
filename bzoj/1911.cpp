#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n;
LL a,b,c;
int q[SZ];
LL f[SZ],s[SZ];

LL G(int x)
{
    return f[x] + a * s[x] * s[x] - b * s[x];
}

int main()
{
    n = read();
    a = read(),b = read(),c = read();
    for(int i = 1;i <= n;i ++) s[i] = s[i - 1] + read();
    int t = 0,w = 0;
    for(int i = 1;i <= n;i ++)
    {
        while(t < w && G(q[t]) - G(q[t + 1]) <
                        2 * a * s[i] * (s[q[t]] - s[q[t + 1]])) t ++;
        int x = s[i] - s[q[t]];
        cout << i << " " << q[t] << endl;
        f[i] = f[q[t]] + a * x * x + b * x + c;
        while(t < w && (G(q[w - 1]) - G(q[w])) * (s[q[w]] - s[i]) <
                        (G(q[w]) - G(i)) * (s[q[w - 1]] - s[q[w]])) w --;
        q[++ w] = i;
    }
    printf("%lld\n",f[n]);
    return 0;
}
