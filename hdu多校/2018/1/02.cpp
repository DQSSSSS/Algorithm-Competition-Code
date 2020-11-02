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

int T,n;
char s[100050];
struct NODE
{
    int x,y;
}a[100050];
int cmp(NODE x,NODE y)
{
	int dx = x.x - x.y;
	int dy = y.x - y.y;
    if(dx > 0 && dy > 0) return x.y > y.y;
    if(dx < 0 && dy < 0) return x.x < y.x;
    return dx < dy;
}


int sumy[100010];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        int ans=0;
        scanf("%d",&n);
        getchar();
        for (int i=1;i<=n;i++)
            {
                int z=0;
                int y=0;
                scanf("%s",s);
                for (int j=0;j<strlen(s);j++)
                    if (s[j]=='(')
                        z++;
                        else if (z>0)
                        {
                            z--;
                            ans+=2;
                        }
                        else y++;
                a[i].x=y;
                a[i].y=z;
            }
        sort(a+1,a+n+1,cmp);
        int zsum=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i].x<=zsum)
            {
                ans+=a[i].x*2;
                zsum-=a[i].x;
            }else
            {
                ans+=zsum*2;
                zsum=0;
            }
            zsum+=a[i].y;
        }
        printf("%d\n",ans);
       // for (int i=1;i<=n;i++)
          //  printf("%d %d\n",a[i].x,a[i].y);
    }
    return 0;
}
/*
4
5
))))(
)))((
))(((
)((((
))))((
3
)((
)))))((
))))))))))((((((((((
3
)(
)((
))(
2
)(((
))(((((
*/
