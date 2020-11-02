#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}


double dfs(double x,double y,int k)
{
    if(x > y) swap(x,y);
//    cout << x << " " << y << " " << k << endl;
    if(k == 1) return y / x;
    double ans = INF;
    double dx = x / k,dy = y / k;
    for(int i = 1;i <= k / 2;i ++)
    {
        double ans1 = max(dfs(dx * i,y,i),dfs(x - dx * i,y,k - i));
        double ans2 = max(dfs(x,dy * i,i),dfs(x,y - dy * i,k - i));
        ans = min(ans,min(ans1,ans2));
    }
    return ans;
}

int main()
{
    int x = read(),y = read(),n = read();
    printf("%.6f",dfs(x,y,n));
    return 0;
}
