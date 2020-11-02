#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const int SZ = 3000010;
const int INF = 1000000010;

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

int a[SZ],b[SZ],n;

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1;i <= n;i ++) a[i] = a[i + n] = read();
        for(int i = 1;i <= n;i ++) b[i] = b[i + n] = read();
        LL ans = -INF,tmp = a[1] - b[1],sum = a[1],d;
        for(int i = 1,j = 2;i <= n;i ++)
        {
            while(tmp >= 0 && j < i + n) tmp += a[j] - b[j],sum += a[j],j ++;
            if(sum > ans)
                ans = sum,d = i - 1;
        //    cout << i << " " << j << " " << sum << " " << tmp << endl;

            sum -= a[i];
            tmp -= a[i] - b[i];
        }
        printf("%d\n",d);
    }
    return 0;
}
