#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;
 
const int MAX=2*100000+10;
int *Rank,r[MAX],sa[MAX],height[MAX];
int wa[MAX],wb[MAX],wm[MAX];
char s[MAX];
 
bool cmp(int *r,int a,int b,int l)
{
    return r[a] == r[b] && r[a+l] == r[b+l];
}
 
void makesa(int *r,int *sa,int n,int m)
{
    int *x=wa,*y=wb,*t;
    for(int i=0; i<m; ++i)wm[i]=0;
    for(int i=0; i<n; ++i)wm[x[i]=r[i]]++;
    for(int i=1; i<m; ++i)wm[i]+=wm[i-1];
    for(int i=n-1; i>=0; --i)sa[--wm[x[i]]]=i;
    for(int i=0,j=1,p=0; p<n; j=j*2,m=p)
    {
        for(p=0,i=n-j; i<n; ++i)y[p++]=i;
        for(i=0; i<n; ++i)if(sa[i]>=j)y[p++]=sa[i]-j;
        for(i=0; i<m; ++i)wm[i]=0;
        for(i=0; i<n; ++i)wm[x[y[i]]]++;
        for(i=1; i<m; ++i)wm[i]+=wm[i-1];
        for(i=n-1; i>=0; --i)sa[--wm[x[y[i]]]]=y[i];
        for(t=x,x=y,y=t,i=p=1,x[sa[0]]=0; i<n; ++i)
        {
            x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
        }
    }
    Rank=x;
}
 
void calheight(int *r,int *sa,int n)
{
    for(int i=0,j=0,k=0; i<n; height[Rank[i++]]=k)
    {
        for(k?--k:0,j=sa[Rank[i]-1]; r[i+k] == r[j+k]; ++k);
    }
}
 
LL calculate(int n,int len,int k)
{
    int *mark=wb,*ans=wm,Top=0;//num[1],num[2]分别表示字符串A,B,suffix(0~i-1)和suffix(i)的最长公共子串>=k的总个数
    LL sum=0,num[3]= {0};
    for(int i=1; i<=n; ++i)
    {
        if(height[i]<k)
        {
            Top=num[1]=num[2]=0;
        }
        else
        {
            for(int size=Top; size && ans[size]>height[i]-k+1; --size) //维护单调栈,ans记录的是suffix(j)和suffix(i-1)>=k的最长公共子串的个数,个数越多表示height[j]越大
            {
                num[mark[size]]+=height[i]-k+1-ans[size];//suffix(j)和suffix(i)>=k的最长公共子串只能是长度为k~height[i],所以需要减去(ans[size]-(height[i]-k+1))
                ans[size]=height[i]-k+1;//更新个数(更新单调栈,使栈里面元素非递减)
            }
            ans[++Top]=height[i]-k+1;
            if(sa[i-1]<len)mark[Top]=1;//由于num新增加的结果是suffix(i-1)和suffix(i)的结果,所以是判断sa[i-1]
            if(sa[i-1]>len)mark[Top]=2;
            num[mark[Top]]+=height[i]-k+1;//增加由suffix(i-1)和suffix(i)产生的结果
            if(sa[i]<len)sum+=num[2];//表示和suffix(i)产生的结果新增加B串的suffix(0~i-1)和suffix(i)>=k的个数
            if(sa[i]>len)sum+=num[1];//表示和suffix(i)产生的结果新增加A串的suffix(0~i-1)和suffix(i)>=k的个数
        }
    }
    return sum;
}
 
int main()
{
    int k1,k2,n,len;
    while(~scanf("%s%d%d",s,&k1,&k2)) {
        for(n=0; s[n] != '\0'; ++n)r[n]=s[n];
        r[len=n]='#';
        for(int i = 0;i < n;i ++) r[n + i + 1] = s[i];
        n = n * 2 + 1;
        for(int i = 0;i <= n;i ++) cout << (char)r[i]; puts("");
        makesa(r,sa,n+1,256);
        calheight(r,sa,n);
        cout<<calculate(n,len,k1)<<endl;
    }
    return 0;
}
