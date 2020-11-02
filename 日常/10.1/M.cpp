#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int SZ = 2000010;
const LL INF = 1000000010;
const LL mod = 1000000007;

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

int n;

map<string,double> mp1;
string s[SZ];
double a[SZ];

int main()
{
    int T = read();
    while(T --)
    {
        mp1.clear();
        int n = read(),m = read();
        for(int i = 1;i <= n;i ++)
        {
            string s;
            double x;
            cin >> s;
            scanf("%lf",&x);
            mp1[s] += x;
        }
        double ans = 0;
        for(int i = 1;i <= m;i ++)
        {
            scanf("%lf",&a[i]);
            cin >> s[i];
            if(s[i] == "JD") ans += a[i];
        }
        for(int i = 1;i <= m;i ++)
        {
        //    cout << s[i] << " " << mp1[s[i]] << " " << a[i] << endl;
            ans += mp1[s[i]] * a[i];
        }
        printf("%.6f\n",ans);
    }
    return 0;
}
