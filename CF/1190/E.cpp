#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<double,double> pdd;
const int SZ = 1e6 + 10;
const int INF = 1073741823 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

double dis(double x,double y) {
    return sqrt(x*x+y*y);
}

int n,K;
pdd a[SZ],b[SZ],c[SZ];
int st[SZ][22];

bool check(double mid) {
    for(int i = 1;i <= n;i ++) {
        double d = acos(mid / dis(a[i].first,a[i].second));
        double x = atan2(a[i].second,a[i].first);
        b[i].first = x - d;
        b[i].second = x + d;
        if(b[i].first <= 0) b[i].first += 2 * PI,b[i].second += 2 * PI;
        b[i+n].first = b[i].first + 2 * PI;
        b[i+n].second = b[i].second + 2 * PI;
    }
    sort(b+1,b+1+2*n);
    double minr = 1e9;
    int m = 0;
    for(int i = 2 * n;i >= 1;i --) {
        if(b[i].second < minr) {
            minr = b[i].second;
            if(b[i].first < 2 * PI)
                c[++ m] = b[i];
        }
    }
    reverse(c+1,c+1+m);
    for(int i = 1;i <= m;i ++) {
        c[m+i].first = c[i].first + 2 * PI;
        c[m+i].second = c[i].second + 2 * PI;
    }

    for(int i = 1,pos = 1;i <= m;i ++) {
        while(pos <= 2 * m && c[pos].first <= c[i].second) pos ++;
        st[i][0] = pos;
    }
    for(int i = 1;i <= m;i ++) st[i+m][0] = st[i][0] + m;

   /*for(int i = 1;i <= 2*m;i ++) {
        printf("%d %.3lf %.3lf %d\n",i,c[i].first,c[i].second,st[i][0]);
    } system("pause");*/

    for(int j = 1;j <= 20;j ++)
        for(int i = 1;i <= 2 * m;i ++)
            st[i][j] = st[st[i][j-1]][j-1];
    for(int i = 1;i <= m;i ++) {
        int now = i;
        for(int j = 0;j <= 20;j ++) {
            if(K >> j & 1) {
                now = st[now][j];
            }
        }
        if(now == 0 || now >= i+m) return true;
    }
    return false;
}

int main() {
    n = read(),K = read();
    double l = 0,r = 1e9;
    for(int i = 1;i <= n;i ++) {
        a[i].first = read(),a[i].second = read();
        r = min(r,dis(a[i].first,a[i].second));
    }

    if(r < eps) return puts("0"),0;

    for(int t = 0;t < 50;t ++) {
        double mid = (l+r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%.10f\n",r);
}
/**
0 3.343 5.438 2
1 3.820 6.366 3
2 5.754 7.988 3
3 9.627 11.721 5
4 10.103 12.649 6
5 12.038 14.271 6
*/
