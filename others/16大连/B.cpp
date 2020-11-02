//litianfeng
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;

const int SZ=1e6+5;

bitset<1005> a[10];
char c[5000005];

inline bool scan_d(int &num)
{
        char in;bool IsN=false;
        in=getchar();
        if(in==EOF) return false;
        while(in!='-'&&(in<'0'||in>'9')) in=getchar();
        if(in=='-'){ IsN=true;num=0;}
        else num=in-'0';
        while(in=getchar(),in>='0'&&in<='9'){
                num*=10,num+=in-'0';
        }
        if(IsN) num=-num;
        return true;
}

int main()
{
	int n;
while(~scanf("%d",&n)){
    
    //scanf("%d",&n);
	for(int i = 0;i < 10;i ++) a[i].reset();
    for (int i = 1; i <= n; i++)
    {
        int t;
        scan_d(t);
        while (t--)
        {
            int x;
            scan_d(x);
            a[x][i - 1] = 1;
        }
    }
    bitset<1005> ans;
    scanf("%s",c);
    int len = strlen(c);
    for (int i = 0; i<len; i++)
    {
        ans <<= 1;
        ans[0] = 1;
        ans &= a[c[i]-'0'];
        if (ans[n-1])
        {
            char s = c[i + 1];
			c[i + 1] = '\0';
			puts(c+i-n+1);
			c[i + 1] = s;
        }
    }
}
    return 0;
}
