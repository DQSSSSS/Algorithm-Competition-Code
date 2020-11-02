#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;

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
}p[SZ];

bool cmp(haha a,haha b) {
	if (a.x!=b.x) return a.x < b.x;
	if (a.y!=b.y) return a.y < b.y;
	return a.id < b.id;
	//return a.x == b.x ? a.id < b.id : a.x < b.x;
}

LL operator *(haha a,haha b) {
	return a.x * b.y - a.y * b.x;
}

haha operator -(haha a,haha b) {
	return (haha){a.x - b.x,a.y - b.y};
}

int S[SZ];

int main(){
	int T = read();
	while(T --) {
        int n = read();
        for(int i = 1;i <= n;i ++) p[i].x = read(),p[i].y = read(),p[i].id = i;
        sort(p + 2,p + n,cmp);
       	int top = 0;
       	S[++ top] = 1;
        for(int i = 2;i <= n;i ++) {
            //while(top > 1 && (p[i] - p[S[top - 1]]) * (p[S[top]] - p[S[top - 1]]) < 0) top --;
            while(top > 1 && p[S[top - 1]] * p[S[top]] > p[S[top - 1]] * p[i] < 0) top --;
      //      while(top > 1 && (p[i] - p[S[top - 1]]) * (p[S[top]] - p[S[top - 1]]) == 0 && p[S[top - 1]] * p[S[top]] == p[S[top - 1]] * p[i] && p[i].id < p[S[top]].id) top --;
            while(top > 1 && p[S[top - 1]] * p[S[top]] == p[S[top - 1]] * p[i] && p[i].id < p[S[top]].id) top --;
            S[++ top] = i;
        }
        for(int i = 1;i <= top;i ++)
        	printf("%lld%c",p[S[i]].id,i == top ? '\n' : ' ');
	}
	return 0;
}
/*
233
4
0 0
3 3
1 1
4 0

*/
