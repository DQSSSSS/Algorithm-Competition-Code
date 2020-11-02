#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 110;
const LL INF = 1e18;
const int mod = 998244353;
const LD eps = 1e-10;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int n,m,id[SZ*2];
double a[SZ][SZ];
///a[i][j]:i��ڼ���Լ�� j��ڼ���Ԫ��
///a[0][i] -> ci Ŀ�꺯���е�i��Ԫ��ϵ��
///a[i][0] -> bi ��i��Լ���еĳ���
///a[i][j] -> Aij ��i��Լ���е�j��Ԫ�ص�ϵ��
///��� sigma(ci*xi),i��N
///Լ�� xj=bj-sigma(aji*xi) ,j��B

///ת��
void pivot(int l,int e)
///�������xe�ʷǻ�������(1~n)  �������xl�ʻ�������(n+1~n+m)
{
    swap(id[n + l],id[e]);
    double t = a[l][e]; a[l][e] = 1;
    for(int j = 0; j <= n;j ++) a[l][j] /= t;
    ///��д������ʽ��
    for(int i = 0; i <= m;i ++)
        if(i != l && fabs(a[i][e]) > eps) {
            t = a[i][e]; a[i][e] = 0;
            for(int j = 0;j <= n;j ++)
                a[i][j] -= a[l][j] * t;
        }
}

///��ʼ��
///����һ������һ���������Թ滮 Ҫ�����-x0
///Լ��Ϊ xj=bj-sigma(aji*xi)+x0 ,j��BȻ����x0�滻bjΪ����Լ��
///������Ƿ�������
bool initialize()
{
    while (1) {
        int e = 0,l = 0;
        for(int i = 1;i <= m;i ++)
            if(a[i][0] < -eps && (!l || (rand()&1)))
                l = i;
        if(!l) break;
        for(int j = 1;j <= n;j ++)
            if(a[l][j] < -eps && (!e || (rand()&1)))
                e = j;
        if(!e) {
            printf("Infeasible\n");
            return false;
        }
        pivot(l,e);
        ///��biΪ����ʱ�򣬰����л�������Ϊ0����һ��Ϸ��ĳ�ʼ��
        ///����ѡ��һ��biΪ���Ļ�����x[i+n]
        ///Ȼ���ڸ�Լ���ұ���һ��ϵ��Ϊ��(��ԭϵ��Ϊ��)�ķǻ���������ת�����
        ///���û��ϵ��Ϊ����Ȼ���޽���
    }
    return true;
}

///���Ż�
bool simplex() {
    while (1) {
        int l = 0,e = 0;
        double minn = INF;
        for(int j = 1;j <= n;j ++)
            if(a[0][j] > eps) {
                e = j; break;
            }
        if(!e) break;
        ///���Ŀ�����ci��С��0 ��ô���Ž���Ƿǻ�������Ϊ0
        for(int i = 1;i <= m;i ++)
            if(a[i][e] > eps && a[i][0] / a[i][e] < minn)
                minn = a[i][0] / a[i][e],l = i;
        ///�����е�ʽ�����ҳ�������ǰѡ���ϵ����Ϊ0���������һ��
        if(!l) {
            printf("Unbounded\n");
            return false;
        }
        ///������е�a[i][e]��С��0��˵������ֵ������
        pivot(l,e);
    }
    return true;
}

double ans[SZ];

int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    srand(time(0));
    int t;
    scanf("%d%d%d",&n,&m,&t);
    //n������ m��Լ��
    for(int i = 1; i <= n;i ++)
        scanf("%lf",&a[0][i]);
    for(int i = 1;i <= m;i ++) {
        for(int j = 1; j <= n;j ++)
            scanf("%lf",&a[i][j]);
        scanf("%lf",&a[i][0]);
    }
    for(int i = 1;i <= n;i ++)
        id[i] = i;
    if(initialize() && simplex()) {
        printf("%.8lf\n",-a[0][0]);
        if(t) {
            for(int i = 1;i <= m;i ++)
                ans[id[n + i]] = a[i][0];
            for(int i = 1;i <= n;i ++)
                printf("%.8lf ",ans[i]);
        }
    }
    return 0;
}
