#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1000000010;

LL read()
{
    char a = getchar();
    LL n = 0; bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,L,R,a[SZ];

deque<int> q1,q2;

int work()
{
    while(q1.size()) q1.pop_front(); //增
    while(q2.size()) q2.pop_front(); //减
    int last = 0,ans = 0;

    for(int i = 1;i <= n;i ++)
    {
        while(q1.size() && a[q1.back()] >= a[i])
            q1.pop_back();
        while(q2.size() && a[q2.back()] <= a[i])
            q2.pop_back();
        q1.push_back(i),q2.push_back(i);
        while(q1.size() && q2.size() && a[q2.front()] - a[q1.front()] > R)
        {
            if(q1.front() < q2.front()) last = q1.front(),q1.pop_front();
            else last = q2.front(),q2.pop_front();
        }
        if(a[q2.front()] - a[q1.front()] >= L)
            ans = max(ans,i - last);
    }
    return ans;
}

int main()
{
    while(~scanf("%d%d%d",&n,&L,&R))
    {
        for(int i = 1;i <= n;i ++)
            scanf("%d",&a[i]);
        printf("%d\n",work());
    }
    return 0;
}
/*
5 1 7
1 9 1 9 2

*/
