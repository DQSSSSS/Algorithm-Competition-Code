#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 2010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

///a[i][j]:i表第几条约束 j表第几个元素
///a[0][i] -> ci 目标函数中第i个元素系数
///a[i][0] -> bi 第i条约束中的常数
///a[i][j] -> Aij 第i条约束中第j个元素的系数
///最大化 sigma(ci*xi),i∈N
///约束 xj=bj-sigma(aji*xi) ,j∈B
namespace dcx {
	int n,m,id[2010];
	double a[50][1100];
	void pivot(int l,int e) { //换入变量l∈[1,n]，替出变量e∈[n+1,n+m]
		swap(id[n + l],id[e]);
		double t = a[l][e]; a[l][e] = 1;
		for(int j = 0;j <= n;j ++) a[l][j] /= t;
		for(int i = 0;i <= m;i ++) { //重写其他式子
			if(i != l && fabs(a[i][e]) > eps) {
				t = a[i][e]; a[i][e] = 0;
				for(int j = 0;j <= n;j ++)
					a[i][j] -= a[l][j] * t;
			}
		}
	}
	bool init() {  //初始化
		while(233) {
			int e = 0,l = 0;
			for(int i = 1;i <= m;i ++)
				if(a[i][0] < -eps && !l)
					l = i;
			if(!l) break;
			for(int j = 1;j <= n;j ++)
				if(a[l][j] < -eps && !e)
					e = j;
			if(!e) {return false; }  //无解
			pivot(l,e);
            //在bi为负的时候，把所有基变量设为0不是一组合法的初始解
        	//所以选择一个bi为负的基变量x[i+n]
        	//然后在该约束右边找一个系数为正(即原系数为负)的非基变量进行转轴操作
        	//如果没有系数为正显然就无解了
		}
		return true;
	}
	
	bool simplex() {  //主程序
		for(int i = 1;i <= n + m;i ++) id[i] = i;
		if(!init()) return false;
		while(233) {
			int l = 0,e = 0;
			double Min = 1e100;
			for(int j = 1;j <= n;j ++)
				if(a[0][j] > eps) { e = j; break; }
			if(!e) break;
			for(int i = 1;i <= m;i ++)
				if(a[i][e] > eps && a[i][0] / a[i][e] < Min)
					Min = a[i][0] / a[i][e],l = i;
			if(!l) { return false; }
			pivot(l,e);
		}
		return true;
	}
	void print() {
		cout << n << " " << m << endl;
		for(int i = 0;i <= m;i ++,puts("")) {
			for(int j = 1;j <= n;j ++)
				printf("%10.5f",a[i][j]);
			printf("%10.5f",a[i][0]);
		}
	}
}

int main() {
	LL n = read(),l = read(),r = read(),k = read();
	LL a,a1,b,b1;
	if(l <= r) a = r - l + 1;
	else a = n - (l - r + 1);
	b = n - a;
	dcx::n = 4; dcx::m = 5;
	dcx::a[0][1] = dcx::a[0][2] = 1;
	dcx::a[0][1] = dcx::a[0][2] = 1;
	return 0;
}
