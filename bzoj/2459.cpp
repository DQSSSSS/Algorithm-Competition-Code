#include<cstdio>
using namespace std;

int main()
{
    int n;
    int x,t = 1;
    scanf("%d%d",&n,&x);
    n --;
    while(n --)
    {
        int xx;
        scanf("%d",&xx);
        if(xx == x) t ++;
        else
        {
            if(-- t < 0) x = xx,t = 1;
        }
    }
    printf("%d\n",x);
    return 0;
}
