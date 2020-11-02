#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const long double eps = 1e-8;

LL read() {
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

double random() {
    return 1.0 * rand() / RAND_MAX;
}

int T = 100000000;
double b = 100;

struct haha {
    double x,y;
}p[15],S[15];

haha operator -(haha a,haha b) {
	return (haha){a.x - b.x,a.y - b.y};
}

double operator *(haha a,haha b) {
    return a.x * b.y - a.y * b.x;
}

double dist(haha a,haha b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool cmp(haha a,haha b) {
    double t = (a - p[1]) * (b - p[1]);
    if(fabs(t) < eps)
    	return dist(a,p[1]) < dist(b,p[1]);
    return t < 0;
}

int graham(int n) {
    int k = 1;
    for(int i = 2;i <= n;i ++)
        if(p[i].x < p[k].x) k = i;
    swap(p[1],p[k]);
    sort(p + 2,p + 1 + n,cmp);
    int top = 0;
    S[++ top] = p[1]; S[++ top] = p[2];
    for(int i = 3;i <= n;i ++) {
        while(top > 1 && (p[i] - S[top - 1]) * (S[top] - S[top - 1]) < 0)
        	top --;
        S[++ top] = p[i];
    }
    return top;
}

long double work(int n) {
    for(int i = 1;i <= n;i ++) {
    	double x = random() * b;
    	double y = random() * b;
        if(x > y) swap(x,y);
        p[i] = (haha){x,y};
    }
    return graham(n);
}

int main() {
    /*for(int i = 8;i <= 10;i ++) {
        long double sum = 0;
        for(int j = 1;j <= T;j ++) {
			sum += work(i);
        }
        cout << i << " " << sum / T << endl;
    }
    while(1);*/
    int n;
    for(int i = 1;i <= 7;i ++) n = read();
    switch(n) {
		case 3 : cout << 3 << endl; break;
		case 4 : cout << 3.66669 << endl; break;
		case 5 : cout << 4.16668 << endl; break;
		case 6 : cout << 4.56648 << endl; break;
		case 7 : cout << 4.90001 << endl; break;
		case 8 : cout << 5.18570 << endl; break;
		case 9 : cout << 5.43571 << endl; break;
		case 10 : cout << 5.65786 << endl; break;
		/*5 4.16668
		6 4.56648
		7 4.90001
		8 5.18576
		9 5.43567

		8 5.18564
		9 5.43574
		10 5.65786*/
    }

	return 0;
}
/*
3 3
4 3.66669
5 4.16668
6 4.56648
7 4.90001
8 5.18576
9 5.43567

8 5.18564
9 5.43574
10 5.65786

*/
