#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<double,double> pii;
const int SZ = 100010;
const double INF = 1e18;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};
const double eps = 1e-6;

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

int n,m;

struct haha {
    int l,r;
    int a,b;
    bool judge(LD x) { return 1.0*a/b<x; }
}p[SZ];

bool cmp(haha a,haha b) { return a.r < b.r; }

LD w[SZ];
LD bits[SZ];

LD ask_min(int x) {
	if(x == 0) return min((LD)0,ask_min(1));
    LD ans = INF;
    for(int i = x;i <= m;i += i & -i)
        ans = min(ans,bits[i]);
    return ans;
}

void add(int x,LD d) {
    for(int i = x;i > 0;i -= i & -i)
        bits[i] = min(bits[i],d);
}

LD check2(LD x){
    LD ret = 0;
    for(int i = 1;i <= m;i ++){
        bits[i]= INF;
    }
    for(int i = 1;i <= n;i ++){
        if(p[i].judge(x)) ret += x*p[i].b - p[i].a;
    }
    for(int i = 1;i <= n;i ++){
        LD now = ask_min(p[i].l-1);
        //cout << x << ' '<< i << ' '<<now << ' ' << pt[i].l << ' ' <<pt[i].r << endl;
        if(!p[i].judge(x)) now +=  p[i].a - x*p[i].b;
        add(p[i].r,now);
    }
    //cout << x << ' '<< sum << ' ' << query(t,t,1,t,1)<<endl;
    return ask_min(m) - ret;
}

LD check(LD k) {
    for(int i = 1;i <= n;i ++) {
    	w[i] = p[i].a - k * p[i].b;
//    	if(w[i] <= 0) ans += w[i];
    }
    //cout << k << endl;
  //  for(int i = 1;i <= n;i ++) cout << w[i] << " "; puts("");
    for(int i = 1;i <= m;i ++) bits[i] = INF;
    for(int i = 1;i <= n;i ++) {
        int r = p[i].r,l = p[i].l;
        LD now = ask_min(l - 1) + w[i];
       // if(w[i] > 0) now += w[i];
        add(r,now);
        /*if(i == n || p[i + 1].r != p[i].r) {
        	add(r,f[r] = now); now = INF;
        }*/
        {
    //    	for(int i = 0;i <= m;i ++) cout << ask_min(i) << " "; puts("");
    	}
    }
    return ask_min(m);
}

LD Div() {
    LD l = 0,r = 1001;
    for(int i = 1;i <= 55;i ++) {
        LD mid = (l + r) / 2.0;
        if(check(mid) <= 0) r = mid;
        else l = mid;
    }
    return r;
}

void getData() {
	n = rand() % 10 + 1,m = rand() % 10 + 1;
	for(int i = 1;i <= n;i ++) {
		int x = rand() % m + 1;
		int y = rand() % m + 1;
		if(x > y) swap(x,y);
		p[i].l = x; p[i].r = y;
		p[i].a = rand() % 10 + 1;
		p[i].b = rand() % 10 + 1;
	}
}

void printData() {
	cout << n << " " << m << endl;
	for(int i = 1;i <= n;i ++) {
		cout << p[i].l << " " << p[i].r << " " << p[i].a << " " << p[i].b << endl;
	}
}

int main() {
	srand(time(0));
    int T = read();
    while(1) {
    	puts("fuck");
        /*n = read(),m = read();
        for(int i = 1;i <= n;i ++) {
            p[i].l = read(),p[i].r = read();
            p[i].a = read(),p[i].b = read();
        }*/
        getData();
        sort(p + 1,p + 1 + n,cmp);
        for(int t = 1;t <= 1000;t ++) {
        	double a = check(t),b = check2(t);
        	if(a <= 100 && b <= 100 && abs(a - b) > eps) {
        		printf("%d %.1f %.1f\n",t,a,b);
        		printData();
				while(1);
        	}
        }
        //for(int i = 1;i <= n;i ++) cout << p[i].l << " " << p[i].r << endl;
        check(1);
       // printf("%.3f\n",(double)Div());
    }
    return 0;
}
/***
1
10 10
1 4 7 4
4 4 1 1
4 5 4 5
1 5 8 8
2 6 4 6
3 7 9 8
7 7 1 3
6 9 3 8
6 10 4 8
2 10 5 2
*/
