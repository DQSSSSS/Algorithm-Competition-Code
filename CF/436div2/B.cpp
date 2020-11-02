#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

typedef long long LL;
const int SZ = 500010;
const int INF = 1000000010;
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

string s;

bool use[300];
int get_ans(int l,int r)
{
    memset(use,0,sizeof(use));
    int t = 0;
    for(int i = l;i <= r;i ++)
    {
        int c = s[i];
        if('A' <= c && c <= 'Z') return -1;
        if(!use[c]) use[c] = 1,t ++;
    }
    return t;
}

int main()
{
    int n = read();
    cin >> s;
    int ans = 0;
    for(int i = 0;i < n;i ++)
        for(int j = i;j < n;j ++)
        {
            ans = max(ans,get_ans(i,j));
        }
    cout << ans << endl;
    return 0;
}
