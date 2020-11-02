#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef long double LD;
typedef pair<int,int> pii;
const int SZ = 200010;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

struct haha {
	LL x,y,id;
}a[SZ];

haha operator -(const haha &a,const haha &b) {
	return (haha){a.x - b.x,a.y - b.y};
}

LL operator *(const haha &a,const haha &b) {
    return a.x * b.y - a.y * b.x;
}

bool cmp(haha a,haha b) {
	if(a.x == b.x && a.y == b.y) return a.id > b.id;
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

int S[SZ];

int main() {
	int T = read();
	while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) {
        	a[i].x = read();
        	a[i].y = read();
        	a[i].id = i;
        }
        sort(a + 1,a + 1 + n,cmp);
        int top = 0;
     //   for(int i = 1;i <= n;i ++) cout << a[i].x << " " << a[i].y << " " << a[i].id << endl;
        for(int i = 1;i <= n;i ++) {
            while(top > 1) {
                LL x = (a[S[top]] - a[S[top - 1]]) * (a[i] - a[S[top - 1]]);
                if(x < 0) break;
                if(x == 0 && a[i].id > a[S[top]].id) break;
            	top --;
            }
			S[++ top] = i;
        }
       // for(int i = 1;i <= top;i ++) cout << a[S[i]].x << " " << a[S[i]].y << endl;
        for(int i = 1;i <= top;i ++) printf("%d%c",a[S[i]].id,i == top ? '\n' : ' ');
	}
	return 0;
}
/**
1
9
4 2
0 0
1 1
2 4
3 3
4 2
4 1
3 0
5 0
*/
