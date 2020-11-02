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

///a[i][j]:i��ڼ���Լ�� j��ڼ���Ԫ��
///a[0][i] -> ci Ŀ�꺯���е�i��Ԫ��ϵ��
///a[i][0] -> bi ��i��Լ���еĳ���
///a[i][j] -> Aij ��i��Լ���е�j��Ԫ�ص�ϵ��
///��� sigma(ci*xi),i��N
///Լ�� xj=bj-sigma(aji*xi) ,j��B
namespace dcx {
	int n,m,id[2010];
	double a[50][1100];
	void pivot(int l,int e) { //�������l��[1,n]���������e��[n+1,n+m]
		swap(id[n + l],id[e]);
		double t = a[l][e]; a[l][e] = 1;
		for(int j = 0;j <= n;j ++) a[l][j] /= t;
		for(int i = 0;i <= m;i ++) { //��д����ʽ��
			if(i != l && fabs(a[i][e]) > eps) {
				t = a[i][e]; a[i][e] = 0;
				for(int j = 0;j <= n;j ++)
					a[i][j] -= a[l][j] * t;
			}
		}
	}
	bool init() {  //��ʼ��
		while(233) {
			int e = 0,l = 0;
			for(int i = 1;i <= m;i ++)
				if(a[i][0] < -eps && !l)
					l = i;
			if(!l) break;
			for(int j = 1;j <= n;j ++)
				if(a[l][j] < -eps && !e)
					e = j;
			if(!e) {return false; }  //�޽�
			pivot(l,e);
            //��biΪ����ʱ�򣬰����л�������Ϊ0����һ��Ϸ��ĳ�ʼ��
        	//����ѡ��һ��biΪ���Ļ�����x[i+n]
        	//Ȼ���ڸ�Լ���ұ���һ��ϵ��Ϊ��(��ԭϵ��Ϊ��)�ķǻ���������ת�����
        	//���û��ϵ��Ϊ����Ȼ���޽���
		}
		return true;
	}
	
	bool simplex() {  //������
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
