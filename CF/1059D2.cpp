#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
struct node{
	int x,y;
}dot[N];
int x[N],y[N];
bool cmp(node a,node b){
	if(a.x==b.x) return a.y>b.y;
	return a.x<b.x;
}
int n;
const double eps=1e-8;
double sqr(double x){
	return x*x;
}
int check(double x){
	double L=1e9;
	for(int i = 1;i<=n;i++){
		if(dot[i].y>2*x) return 0;
		if(dot[i].y<x){
			double len=sqrt(sqr(x)-sqr(x-dot[i].y));
			L=min(L,dot[i].x+len);
			continue;
		}
		double len=sqrt(sqr(x)-sqr(dot[i].y-x));
		L=min(L,dot[i].x+len);
	}
	//if(L==1e9) return 1;
	for(int i = 1;i<=n;i++){
		if(sqr(dot[i].x-L)+sqr(dot[i].y-x)>sqr(x)+eps) return 0;
	}
	return 1;
}


int check2(int X,int R){
	for(int i = 1;i<=n;i++){
		if(sqr(dot[i].x-X)+sqr(dot[i].y-R)>sqr(R)+eps) return 0;
	}
	return 1;
}

int main(){
	//int n;
	scanf("%d",&n);
	int flag1=0,flag2=0,flag3=0;
	int X;
	for(int i = 1;i<=n;i++){
		scanf("%d%d",&dot[i].x,&dot[i].y);
		if(dot[i].y==0) flag3++,X=dot[i].x;
		if(dot[i].y<0) flag1=1;
		if(dot[i].y>0) flag2=1;
	}
	if(flag1&&flag2||flag3>1){
		printf("-1\n");
		return 0;
	}
	if(flag1){
		for(int i = 1;i<=n;i++) dot[i].y=-dot[i].y;
	}
	sort(dot+1,dot+n+1,cmp);
	if(flag3==1){
		double L=0,R=1e14;
		for(int i = 1;i <= 100;i++){
			double mid=(L+R)/2;
			if(check2(X,mid)){
				R=mid;
			}else L=mid;
		}
		printf("%.8lf",L);
		return 0;
	}
	double L=0,R=1e14;
	for(int i = 1;i <= 100;i++){
		double mid=(L+R)/2;
		if(check(mid)){
			R=mid;
		}else L=mid;
		
	}
	printf("%.8lf\n",L); 
	
}
