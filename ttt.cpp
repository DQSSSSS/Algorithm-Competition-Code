
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 1001001
using namespace std;
struct abcd{
    int to,next;
}table[M<<1];
int head[M],tot;
int n,m;
int result[M],state[M],T;
void Add(int x,int y)
{
    table[++tot].to=y;
    table[tot].next=head[x];
    head[x]=tot;
}
bool Hungary(int x)
{
    int i;
    for(i=head[x];i;i=table[i].next)
    {
        if(state[table[i].to]==T)
            continue;
        state[table[i].to]=T;
        if( !result[table[i].to] || Hungary(result[table[i].to]) )
        {
            result[table[i].to]=x;
            return true;
        }
    }
    return false;
}
int main()
{
    int i,x,y;
    cin>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        Add(x,i);Add(y,i);
    }
    for(i=1;i<=10000;i++)
    {
        ++T;
        if( !Hungary(i) )
            break;
    }
    cout<<i-1<<endl;
}
