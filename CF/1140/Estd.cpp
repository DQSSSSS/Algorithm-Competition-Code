#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int N=500005,P=998244353;
int n,k,a[N],b[N],m,f[N];

inline void read(int &i){
	i=0;char c=getchar();bool j=0;
	for(;!isdigit(c);c=getchar())if(c=='-')j=1;
	for(;isdigit(c);c=getchar())i=(i<<1)+(i<<3)+c-'0';i=j?-i:i;
}
inline ll Pow(ll a,int b){ll c=1;for(;b;a=a*a%P,b>>=1)if(b&1)c=c*a%P;return c;}

inline int F(int n,int c,int t){
	if(!c)return k*Pow(k-1,n-1)%P;
	if(c==1)return Pow(k-1,n);
	f[0]=1;
	int ans=0;
	for(int i=1;i<=n;++i)f[i]=1ll*f[i-1]*(k-1)%P;
	for(int i=n;i>=1;--i){
		if((n-i)&1)ans-=f[i];
		else ans+=f[i];
		ans%=P;
	}
	if(ans<0)ans+=P;
	if(!t){
		ans=Pow(k-1,n+1)-ans;
		if(ans<0)ans+=P;
		ans=ans*Pow(k-1,P-2)%P;
	}
	return ans;
}

int calc(){
	for(int i=1;i<m;++i)if(b[i]>0&&b[i+1]>0&&b[i]==b[i+1])return 0;
	int as=1;
	for(int i=1;i<=m;){
		int j=i;
		if(b[i]!=-1){i++;continue;}
		while(j+1<=m&&b[j+1]==-1)j++;
		int c=0;
		if(i>1)c++;
		if(j<m)c++;
		as=1ll*as*F(j-i+1,c,b[i-1]==b[j+1])%P;
		i=j+1;
	}
	return as;
}

int main(){
    freopen("data.in","r",stdin);
    freopen("std.out","w",stdout);
	read(n);read(k);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;i+=2)b[++m]=a[i];
	int ans=calc();
	m=0;
	for(int i=2;i<=n;i+=2)b[++m]=a[i];
	ans=1ll*ans*calc()%P;
	printf("%d\n",ans);
	return 0;
}
