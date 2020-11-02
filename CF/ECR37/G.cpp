#include<bits/stdc++.h>

using namespace std;  

typedef long long LL;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') { n = n *10 +a - '0'; a = getchar(); }
	if(flag) n = -n;
	return n;
}

__int64 a[1000],num;  
void init(__int64 n)//求一个数的质因子  
{  
    __int64 i;  
    num=0;  
    for(i=2;i*i<=n;i++)  
    {  
        if(n%i==0)  
        {  
            a[num++]=i;  
            while(n%i==0)  
                n=n/i;  
        }  
    }  
    if(n>1)//这里要记得  
        a[num++]=n;  
}  
__int64 haha(__int64 m)//用队列数组实现容斥原理  
{  
    __int64 que[10000],i,j,k,sum=0;  
    LL t=0;  
    que[t++]=-1;  
    for(i=0;i<num;i++)  
    {  
        k=t;  
        for(j=0;j<k;j++)  
           que[t++]=que[j]*a[i]*(-1);  
    }  
    for(i=1;i<t;i++)  
        sum=sum+m/que[i];  
    return sum;  
}  
LL work(LL x,LL y,LL n)
{  
	if(x > y) return 0;
    LL sum=y-haha(y)-(x-1-haha(x-1));  
    return sum;
}  

LL x,y,k;

LL Div()
{
	LL l = 0,r = 1e9;
	while(r - l > 1)
	{
		LL mid = l + r >> 1;
		if(work(x,mid,y) < k) l = mid;
		else r = mid;
	}
	return r;
}

int main()
{
	int T = read();
	while(T --)
	{
		memset(a,0,sizeof(a));
		x = read(),y = read(),k = read();
		x ++;
		init(y);
		printf("%I64d\n",Div());
	}
	return 0;
}
